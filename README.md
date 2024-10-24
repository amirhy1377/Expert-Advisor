
1. Headers
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>: Used for standard input and output (like std::cout).
#include <vector>: Used for the std::vector data type, which is a dynamic array.
#include <thread>: Used for thread-related functionalities, such as putting threads to sleep.
#include <chrono>: Used for time units (like minutes, seconds, etc.).




2. Global Variables
std::vector<double> shortTermPrices;
std::vector<double> longTermPrices;
These two std::vector arrays are used to store market prices over short-term and long-term periods.


3. getMarketPrice Function
double getMarketPrice() {
    return 1.12345; // Sample price
}
This function returns a sample price (1.12345). In a real application, this function should be replaced with code to retrieve the price from the broker's API.



4. calculateMovingAverage Function
double calculateMovingAverage(const std::vector<double>& prices, int period) {
    if (prices.size() < period) return 0.0; // If there aren't enough prices
    double sum = 0.0;
    for (int i = prices.size() - period; i < prices.size(); ++i) {
        sum += prices[i];
    }
    return sum / period;
}
This function calculates the moving average.
If the number of stored prices is less than the specified period, it returns 0.0.
Otherwise, it computes the sum of prices over the specified period and returns the average.




5. tradingStrategy Function
void tradingStrategy() {
    double currentPrice = getMarketPrice();
    shortTermPrices.push_back(currentPrice);
    longTermPrices.push_back(currentPrice);

    double shortMovingAverage = calculateMovingAverage(shortTermPrices, 5);
    double longMovingAverage = calculateMovingAverage(longTermPrices, 20);

    if (shortMovingAverage > longMovingAverage) {
        std::cout << "Buy!" << std::endl;
    } else if (shortMovingAverage < longMovingAverage) {
        std::cout << "Sell!" << std::endl;
    }
}
This function implements the trading strategy.
It retrieves the current price using the getMarketPrice function and adds it to both the short-term and long-term price vectors.
It calculates the short-term (5 periods) and long-term (20 periods) moving averages.
If the short-term moving average is greater than the long-term moving average, it prints "Buy!" If it's less, it prints "Sell!"



6. main Function
int main() {
    while (true) {
        tradingStrategy();
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
    return 0;
}
This function is the entry point of the program.
In an infinite loop (while (true)), it repeatedly calls the tradingStrategy function.
Then, it puts the program to sleep for 1 minute (using std::this_thread::sleep_for(std::chrono::minutes(1))) to create a pause between each execution of the strategy.
Conclusion
This code represents a simple trading strategy that uses moving averages to allow you to automatically make buy and sell decisions. In a real-world implementation, it would need to be updated with real prices and also include error handling and management of various market conditions.



بیایید قسمت‌های مختلف این کد را بررسی کنیم:

1. هدرها
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>: برای استفاده از ورودی و خروجی استاندارد (مثل std::cout).
#include <vector>: برای استفاده از نوع داده‌ای std::vector، که یک آرایه دینامیک است.
#include <thread>: برای استفاده از قابلیت‌های مربوط به نخ (thread)، مثل خواباندن نخ‌ها.
#include <chrono>: برای استفاده از واحدهای زمانی (مثل دقیقه، ثانیه و غیره).
2. متغیرهای جهانی

std::vector<double> shortTermPrices;
std::vector<double> longTermPrices;
این دو آرایه از نوع std::vector برای ذخیره‌سازی قیمت‌های بازار در دوره‌های زمانی کوتاه‌مدت و بلندمدت استفاده می‌شوند.
3. تابع getMarketPrice

double getMarketPrice() {
    return 1.12345; // قیمت فرضی
}
این تابع یک قیمت فرضی (1.12345) را برمی‌گرداند. در واقعیت، باید این تابع با کدی برای دریافت قیمت از API بروکر جایگزین شود.
4. تابع calculateMovingAverage

double calculateMovingAverage(const std::vector<double>& prices, int period) {
    if (prices.size() < period) return 0.0; // اگر تعداد قیمت‌ها کافی نیست
    double sum = 0.0;
    for (int i = prices.size() - period; i < prices.size(); ++i) {
        sum += prices[i];
    }
    return sum / period;
}
این تابع میانگین متحرک را محاسبه می‌کند.
اگر تعداد قیمت‌های ذخیره‌شده کمتر از دوره مورد نظر (period) باشد، مقدار 0 برمی‌گرداند.
در غیر این صورت، مجموع قیمت‌ها را در دوره مورد نظر محاسبه کرده و میانگین آن را برمی‌گرداند.
5. تابع tradingStrategy
void tradingStrategy() {
    double currentPrice = getMarketPrice();
    shortTermPrices.push_back(currentPrice);
    longTermPrices.push_back(currentPrice);

    double shortMovingAverage = calculateMovingAverage(shortTermPrices, 5);
    double longMovingAverage = calculateMovingAverage(longTermPrices, 20);

    if (shortMovingAverage > longMovingAverage) {
        std::cout << "خرید!" << std::endl;
    } else if (shortMovingAverage < longMovingAverage) {
        std::cout << "فروش!" << std::endl;
    }
}
این تابع استراتژی معامله را پیاده‌سازی می‌کند.
قیمت فعلی را با استفاده از تابع getMarketPrice دریافت می‌کند و آن را به آرایه‌های قیمت‌های کوتاه‌مدت و بلندمدت اضافه می‌کند.
میانگین متحرک‌های کوتاه‌مدت (۵ دوره) و بلندمدت (۲۰ دوره) محاسبه می‌شود.
اگر میانگین متحرک کوتاه‌مدت بیشتر از میانگین بلندمدت باشد، پیغام "خرید!" چاپ می‌شود و اگر کمتر باشد، پیغام "فروش!" چاپ می‌شود.
6. تابع main

int main() {
    while (true) {
        tradingStrategy();
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
    return 0;
}
این تابع نقطه ورود به برنامه است.
در یک حلقه بی‌نهایت (while (true))، تابع tradingStrategy به طور مکرر فراخوانی می‌شود.
سپس برنامه به مدت ۱ دقیقه می‌خوابد (با استفاده از std::this_thread::sleep_for(std::chrono::minutes(1))) تا بین هر بار اجرای استراتژی وقفه‌ای ایجاد کند.
نتیجه‌گیری
این کد یک استراتژی ساده برای معامله است که با استفاده از میانگین‌های متحرک به شما اجازه می‌دهد تا به صورت خودکار تصمیمات خرید و فروش بگیرید. 
