#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

template<typename T>
T GetMaximum(T first_number, T second_number) {
    if (first_number >= second_number) {
        return first_number;
    } else {
        return second_number;
    }
}

void DemonstrateFunctionTemplate() {
    std::cout << "max(3, 4) = " << GetMaximum(3, 4) << '\n'
    << "max(3.1, 4.1) = " << GetMaximum(3.1, 4.1) << '\n'
    << "max(3, 4.5) = " << GetMaximum<int>(3, 4.5) << '\n'
    << "max(3, 4.5) = " << GetMaximum<double>(3, 4.5) << '\n';
}

struct Student {
    long long int id_;
    double gpa_;
};

template<typename T>
class Store {
    private:
        T item_;
        bool have_stored_item_;
    public:
        Store();
        void PutElement(T item) {
            item_ = item;
            have_stored_item_ = true;
        }
        T GetElement() const;
};

template<typename T>
Store<T>::Store(): have_stored_item_(false) {}

template<typename T>
T Store<T>::GetElement() const {
    if (!have_stored_item_) {
        std::cout << "No item present!\n";
        std::exit(1);
    }
    return item_;
}

void DemonstrateClassTemplate() {
    Store<int> no1_item;
    Store<Student> no2_item;
    no1_item.PutElement(16);
    Student sample_student = {2026, 4.01};
    no2_item.PutElement(sample_student);
    std::cout << no1_item.GetElement() << '\n'
    << no2_item.GetElement().id_ << '\n';
}

int main() {
    return 0;
}