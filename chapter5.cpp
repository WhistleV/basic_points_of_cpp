#include <iostream>

void Combination(int m = 5, int n = 2) {
    auto Factorial = [](int factorial_times) {
        int factorial_x = 1;
        for (int idx = factorial_times; idx > 0; --idx) {
            factorial_x *= idx;
        }
        return factorial_x;
    };
    int combination = Factorial(m) / (Factorial(n) * Factorial(m - n));
    std::cout << combination << std::endl;
}

void Power(double base = 2, int exponent = 10) {
    double powered_result = 1.0;
    for (int idx = 0; idx < exponent; ++idx) {
        powered_result *= base;
    }
    std::cout << powered_result << std::endl;
}

bool IsRightTriangle(double a = 3, double b = 4, double c = 5) {
    if ((a * a + b * b == c * c) || 
    (b * b + c * c == a * a) || 
    (c * c + a * a == b * b)) {
        return true;
    } else {
        return false;
    }
}

const int kSize = 3;
int matrix[kSize][kSize] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
void SumDiagonal(int (*ptr_matrix)[kSize] = matrix) {
    int total = 0;
    for (int i = 0; i < kSize; ++i) {
        for (int j = 0; j < kSize; ++j) {
            if (i == j || i + j == kSize - 1) {
                total += *(*(ptr_matrix + i) + j);
            }
        }
    }
    std::cout << total << std::endl;
}

int FactorialRecursion(int n = 5) {
    if (n < 0) {
        std::cout << "Invalid input." << std::endl;
        return -1;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * FactorialRecursion(n - 1);
    }
}

template <typename T>
void Display(T value) {
    std::cout << value << std::endl;
}

int main() {
    SumDiagonal();
    return 0;
}