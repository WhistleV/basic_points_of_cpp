#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

void CalculateCircleArea() {
    const double kPi = 3.14;
    double radius = 10.0;
    double area = kPi * pow(radius, 2);
    std::cout << area << std::endl;
}

void TemperatureConversion() {
    double fahrenheit = 100;
    double celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.1f", celsius);
}

void CheckLeapYear() {
    int year;
    std::cin >> year;
    bool is_leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (is_leap) {
        std::cout << year << " is leap year." << std::endl;
    } else {
        std::cout << year << " isnt leap year." << std::endl;
    }
}

void PrintDigitSum() {
    int number;
    std::cin >> number;
    int hundreds = number / 100;
    int tens = number / 10 % 10;
    int ones = number % 10;
    int summation = hundreds + tens + ones;
    std::cout << summation << std::endl;
}

int main() {
    return 0;
}