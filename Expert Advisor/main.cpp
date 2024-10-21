#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// تعریف متغیرهای برای ذخیره‌سازی قیمت‌ها
std::vector<double> shortTermPrices;
std::vector<double> longTermPrices;

// تابع برای دریافت قیمت بازار
double getMarketPrice() {
    return 1.12345; // قیمت فرضی
}

// تابع برای محاسبه میانگین متحرک
double calculateMovingAverage(const std::vector<double>& prices, int period) {
    if (prices.size() < period) return 0.0; // اگر تعداد قیمت‌ها کافی نیست
    double sum = 0.0;
    for (int i = prices.size() - period; i < prices.size(); ++i) {
        sum += prices[i];
    }
    return sum / period;
}

// استراتژی معامله
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

int main() {
    while (true) {
        tradingStrategy();
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
    return 0;
}
