#include <iostream>
#include <iomanip>
#include <cmath>

//默认构造函数 类外定义成员函数 默认复制构造函数与对象赋值方法
class MyClock {
    private:
        int hour_, minute_, second_;
    public:
        MyClock(int h = 0, int m = 0, int s = 0) {
            hour_ = h;
            minute_ = m;
            second_ = s;
        }
        MyClock(const MyClock& other) {
            hour_ = other.hour_;
            minute_ = other.minute_;
            second_ = other.second_;
            std::cout << "Copy constructor is called." << std::endl;
        }
        void SetTime(int h, int m, int s) {
            if ((h >= 0 && h <= 23) 
            && (m >= 0 && m <= 59) 
            && (s >= 0 && s <= 59)) {
                hour_ = h;
                minute_ = m;
                second_ = s;
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        void ShowTime() const;
};

void MyClock::ShowTime() const {
    std::cout << std::setw(2) << std::setfill('0') << hour_ << ':'
    << std::setw(2) << std::setfill('0') << minute_ << ':'
    << std::setw(2) << std::setfill('0') << second_ << std::endl;
}

void ShowDifferenceBetweenObjectAssignAndCopyConstructor() {
    MyClock no1_clock(17, 39, 15);
    no1_clock.ShowTime();
    no1_clock.SetTime(17, 45, 30);
    no1_clock.ShowTime();
    MyClock no2_clock;
    no2_clock = no1_clock;
    std::cout << "Object assigned." << std::endl;
    no2_clock.ShowTime();
    MyClock no3_clock(no1_clock);
    no3_clock.ShowTime();
}

//析构函数 构造函数初始化列表
class Circle {
    private:
        double radius_;
    public:
        const double kPi = 3.14159;
        Circle(double radius = 0) : radius_(radius) {
            std::cout << "Constructor is called." << std::endl;
        }
        ~Circle() {
            std::cout << "Destructor is called." << std::endl;
        }
        void SetRadius(int radius) {
            radius_ = radius;
        }
        void ShowRadius() {
            std::cout << "Radius now: " << radius_ << std::endl;
        }
        double GetArea() const {
            return kPi * pow(radius_, 2);
        }
        double GetCircumference() const {
            return 2 * kPi * radius_;
        }
        double GetCircleRadiusOfDoubleArea() const {
            return sqrt(2 * GetArea() / kPi);
        }
};

void ShowDestructor() {
    Circle sample_circle(10);
    std::cout << "S = " << sample_circle.GetArea() << std::endl;
    std::cout << "C = " << sample_circle.GetCircumference() << std::endl;
    std::cout << "The radius of circle that has double area of this: " 
    << sample_circle.GetCircleRadiusOfDoubleArea() << std::endl;
    sample_circle.SetRadius(15);
    sample_circle.ShowRadius();
}

//类的组合 友元类 友元函数
class Point {
    friend class Line;
    friend double FriendFunctionGetLength(const Point& start_point, const Point& end_point);
    private:
        double x_, y_;
    public:
        Point(const double& x, const double& y) : x_(x), y_(y) {}
        double GetX() const {
            return x_;
        }
        double GetY() const {
            return y_;
        }
};

class Line {
    private:
        Point start_point_, end_point_;
    public:
        Line(const Point& start_point, const Point& end_point)
        : start_point_(start_point), end_point_(end_point) {}
        double MemberFunctionGetLength() const {
            double distance_x = start_point_.GetX() - end_point_.GetX();
            double distance_y = start_point_.GetY() - end_point_.GetY();
            return sqrt(pow(distance_x, 2) + pow(distance_y, 2));
        }
        double FriendClassGetLength() const {
            double distance_x = start_point_.x_ - end_point_.x_;
            double distance_y = start_point_.y_ - end_point_.y_;
            return sqrt(pow(distance_x, 2) + pow(distance_y, 2));
        }
};

double FriendFunctionGetLength(const Point& start_point, const Point& end_point) {
            double distance_x = start_point.x_ - end_point.x_;
            double distance_y = start_point.y_ - end_point.y_;
            return sqrt(pow(distance_x, 2) + pow(distance_y, 2));
        }

void DemonstrateClassCombination() {
    Point no1_point(0, 0), no2_point(3,4);
    Line line(no1_point, no2_point);
    std::cout << "Member function: " << line.MemberFunctionGetLength() << std::endl;
    std::cout << "Friend class: " << line.FriendClassGetLength() << std::endl;
    std::cout << "Friend function: " << FriendFunctionGetLength(no1_point, no2_point) << std::endl;
}

//运算符重载为成员函数或友元函数
class Complex {
    friend Complex operator-(const Complex& left_complex, const Complex& right_complex);
    private:
        double real_, imag_;
    public:
        Complex(const double& real, const double& imag)
        : real_(real), imag_(imag) {}
        void DisplayComplex() {
            std::cout << real_ << " + " << imag_ << " i" << std::endl;
        }
        Complex operator+(const Complex& other) const {
            double new_real = real_ + other.real_;
            double new_imag = imag_ + other.imag_;
            return Complex(new_real, new_imag);
        }
};

Complex operator-(const Complex& left_complex, const Complex& right_complex) {
    double new_real = left_complex.real_ - right_complex.real_;
    double new_imag = left_complex.imag_ - right_complex.imag_;
    return Complex(new_real, new_imag);
}

void DemonstrateComplex() {
    Complex no1_complex(3.0, 1.0), no2_complex(5.0, 4.0);
    Complex add_result = no1_complex + no2_complex, subtract_result = no1_complex - no2_complex;
    add_result.DisplayComplex();
    subtract_result.DisplayComplex();
}

//静态数据成员与静态成员函数
class Book {
    private:
        static int book_count_;
        const char* book_id_;
    public:
        Book(const char* book_id) : book_id_(book_id) {
            book_count_++;
        }
        static int GetBookCount() {
            return book_count_; 
        }
};

int Book::book_count_ = 0;

void DemonstrateStaticMember() {
    Book no1_book("RiGuangLiuNian");
    Book no2_book("DingZhuangMeng");
    Book no3_book("ShouHuo");
    std::cout << "Book count: " << Book::GetBookCount() << std::endl;
}

int main() {
    return 0;
}