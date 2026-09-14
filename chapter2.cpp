#include <iostream>
#include <cstdio>

void PrintMaxOfTwo() {
    int first_number, second_number;
    std::cin >> first_number >> second_number;
    int maximum = first_number;
    if (second_number > maximum) {
        maximum = second_number;
    }
    std::cout << maximum << std::endl;
}

void CheckSpeed() {
    int velocity;
    std::cin >> velocity;
    if (velocity > 60) {
        std::cout << "speed" << std::endl;
    } else {
        std::cout << "normal" << std::endl;
    }
}

void PrintMaxOfTwoWithTernary() {
    int first_number, second_number;
    std::cin >> first_number >> second_number;
    int maximum = (first_number > second_number) ? first_number : second_number;
    std::cout << maximum << std::endl;
}

void CalculateDiscount() {
    double amount;
    std::cin >> amount;
    if (amount >= 300) {
        std::cout << amount * 0.9 << std::endl;
    } else if (amount >= 200) {
        std::cout << amount * 0.95 << std::endl;
    } else if (amount >= 100) {
        std::cout << amount * 0.98 << std::endl;
    } else {
        std::cout << amount << std::endl;
    }
}

void SortThreeNumbers() {
    int x = 9, y = 5, z = 3;
    if (x >= y && x >= z) {
        if (y >= z) {
            std::cout << x << y << z << std::endl;
        } else {
            std::cout << x << z << y << std::endl;
        }
    } else if (y >= x && y >= z) {
        if (x >= z) {
            std::cout << y << x << z << std::endl;
        } else {
            std::cout << y << z << x << std::endl;
        }
    } else {
        if (x >= y) {
            std::cout << z << x << y << std::endl;
        } else {
            std::cout << z << y << x << std::endl;
        }
    }
}

void CalculateExpression() {
    int fn, sn;
    char ope;
    std::cin >> fn >> ope >> sn;
    switch (ope) {
        case 'a':
        case '+':
            printf("%d %c %d = %d\n", fn, ope, sn, fn + sn);
            break;
        case 's':
        case '-':
            printf("%d %c %d = %d\n", fn, ope, sn, fn - sn);
            break;
        case 'm':
        case '*':
            printf("%d %c %d = %d\n", fn, ope, sn, fn * sn);
            break;
        case 'd':
        case '/':
            if (sn != 0) {
                printf("%d %c %d = %d\n", fn, ope, sn, fn / sn);
            } else {
                std::cout << "Division cant be zero." << std::endl;
            }
            break;
        default:
            std::cout << "error" << std::endl;
    }
}

int main() {
    return 0;
}