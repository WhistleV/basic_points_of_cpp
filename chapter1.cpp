#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <random>

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

struct Person {
    const char* name_ = "WhistleV";
    long long int id_;
    const char* gender_;
    int birthday_;
    void SayHello() {
        std::cout << name_ << ": Hello!" << std::endl;
    }
};

void DemonstrateStruct() {
    Person WhistleV;
    WhistleV.SayHello();
    Person xiao_ming = {"Xiao Ming", 2026123456789, "male", 20070616};
    Person xiao_ming_clone(xiao_ming);
    Person xiao_hong = {"Xiao Hong", 2026987654321, "female", 20060717};
    Person person_list[3] = {xiao_ming, xiao_hong, xiao_ming_clone};
    for (int idx = 0; idx < 3; ++idx) {
        std::cout << (*(person_list + idx)).name_ << ' ' << (*(person_list + idx)).id_ << ' '
        << (*(person_list + idx)).gender_ << ' ' << (*(person_list + idx)).birthday_ << std::endl;
    }
}

enum Color {kRed = 2, kYellow, kBlue, kOrange = 5, kPurple, kGreen};

void DemonstrateEnumeration() {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(2, 4);
    Color base_color = static_cast<Color>(distribution(generator));
    Color mixed_color = static_cast<Color>(base_color + distribution(generator));
    std::cout << mixed_color << std::endl;
}

int main() {
    DemonstrateEnumeration();
    return 0;
}