#include <iostream>
#include <cmath>

//继承与派生 同名覆盖
class Person {
    protected:
        const char* name_;
        int age_;
    public:
        bool is_working_ = true;
        Person(const char* name = "", int age = 0)
        : name_(name), age_(age) {}
        void ShowPersonInformation() const {
            std::cout << "name: " << name_ << '\n'
            << "age: " << age_ << '\n';
        }
            void ShowStatus() const {
            std::cout << "working" << '\n';
        }
};

class Student: public Person {
    private:
        const char* major_;
    public:
        bool is_working_ = false;
        Student(const char* name = "", int age = 0, const char* major = "")
        : Person(name, age), major_(major) {}
        void ShowStudentInformation() const {
            ShowPersonInformation();
            std::cout << "major: " << major_ << '\n';
        }
        void ShowStatus() const {
            std::cout << "studying" << '\n';
        }
};

void DemonstrateSingleInheritanceAndNameHiding() {
    Student sample_student("WhistleV_", 19, "Computer Science");
    sample_student.ShowStudentInformation();
    sample_student.ShowStatus();
    sample_student.Person::ShowStatus();
    std::cout << sample_student.is_working_ << '\n'
    << sample_student.Person::is_working_ << '\n';
}

//虚函数与运行时多态 类型兼容规则
class Animal {
    public:
        virtual void Speak() const {
            std::cout << "Duang!" << '\n';
        }
};

class Dog: public Animal {
    public:
        void Speak() const override {
            std::cout << "Woof!" << '\n';
        }
};

class Cat: public Animal {
    public:
        void Speak() const override {
            std::cout << "Meow!" << '\n';
        }
};

void MakeSpeak(const Animal& animal) {
    animal.Speak();
}

void ShowRuntimePolymorphism() {
    Dog sample_dog;
    Cat sample_cat;
    MakeSpeak(sample_dog);
    MakeSpeak(sample_cat);
}

//纯虚函数与抽象类
class Shape {
    protected:
        const char* name_;
    public:
        Shape(const char* name = ""): name_(name) {}
        virtual double GetArea() const = 0;
        virtual void ShowInformation() const = 0;
};

class Circle: public Shape {
    private:
        double radius_;
        const double kPi = 3.14;
    public:
        Circle(const char* name = "", double radius = 0.0)
        : Shape(name), radius_(radius) {}
        double GetArea() const override {
            return kPi * pow(radius_, 2);
        }
        void ShowInformation() const override {
            std::cout << "shape: " << name_ << '\n'
            << "radius: " << radius_ << '\n';
        }
};

class Rectangle: public Shape {
    private:
        double length_, width_;
    public:
        Rectangle(const char* name = "", double length = 0.0, double width = 0.0)
        : Shape(name), length_(length), width_(width) {}
        double GetArea() const override {
            return length_ * width_;
        }
        void ShowInformation() const override {
            std::cout << "shape: " << name_ << '\n'
            << "length: " << length_ << '\n'
            << "width: " << width_ << '\n'; 
        }
};

void DemonstrateAbstractClass() {
    Circle sample_circle("circle", 5.0);
    Rectangle sample_rectangle("rectangle", 4.0, 6.0);
    sample_circle.ShowInformation();
    std::cout << "area: " << sample_circle.GetArea() << '\n';
    sample_rectangle.ShowInformation();
    std::cout << "area: " << sample_rectangle.GetArea() << '\n';
}

int main() {
    return 0;
}