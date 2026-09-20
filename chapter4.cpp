#include <iostream>
#include <memory>

void AnalyzeCourseScores() {
    const int kNumberOfCourses = 10;
    double score_list[kNumberOfCourses] = {}, summation_of_scores = 0.0;
    for (int idx = 0; idx < kNumberOfCourses; ++idx) {
        std::cin >> score_list[idx];
        summation_of_scores += score_list[idx];
    }
    double average_of_scores = summation_of_scores / kNumberOfCourses;
    int higher_than_average_count = 0, lower_than_average_count = 0;
    for (int idx = 0; idx < kNumberOfCourses; ++idx) {
        if (score_list[idx] < average_of_scores) {
            higher_than_average_count++;
        }
        else if (score_list[idx] > average_of_scores) {
            lower_than_average_count++;
        }
        else {}
    }
    std::cout << average_of_scores << higher_than_average_count << lower_than_average_count << std::endl;
}

void CountWords() {
    const int kMaxLengthOfSentence = 100;
    char sentence[kMaxLengthOfSentence] = {};
    std::cin.getline(sentence, kMaxLengthOfSentence);
    int word_count = 0;
    bool is_in_word = false;
    for (int idx = 0; sentence[idx] != '\0'; ++idx) {
        if (sentence[idx] != ' ' && is_in_word == false) {
            word_count++;
            is_in_word = true;
        }
        else if (sentence[idx] == ' ' && is_in_word == true) {
            is_in_word = false;
        }
    }
    std::cout << sentence << ' ' << word_count << std::endl;
}

void TransposeMatrix() {
    const int kSize = 3;
    int matrix[kSize][kSize] = {};
    for (auto& row: matrix) {
        for (auto& element_in_row: row) {
            std::cin >> element_in_row;
        }
    }
    for (int column = 0; column < kSize; ++column) {
        for (const auto& row: matrix) {
            std::cout << row[column] << ' ';
        }
        std::cout << std::endl;
    }
}

void SwapByPointer() {
    int first_number, second_number;
    std::cin >> first_number >> second_number;
    int* former_pointer = &first_number;
    int* latter_pointer = &second_number;
    int* temporary_pointer = nullptr;
    std::cout << first_number << '\t' << second_number << std::endl;
    temporary_pointer = former_pointer;
    former_pointer = latter_pointer;
    latter_pointer = temporary_pointer;
    std::cout << *former_pointer << '\t' << *latter_pointer << std::endl;
}

void SumArrayByPointer() {
    const int kElementCount = 5;
    int array[kElementCount] = {};
    int* pointer = array;
    for (int idx = 0; idx < kElementCount; ++idx) {
        std::cin >> *(array + idx);
    }
    int summation_of_double_elements_in_array = 0;
    for (int idx = 0; idx < kElementCount; ++idx) {
        summation_of_double_elements_in_array += *pointer *= 2;
        pointer++;
    }
    std::cout << summation_of_double_elements_in_array << std::endl;
}

void SumStudentScores() {
    const int kStudentCount = 3;
    const int kSubjectCount = 3;
    int score_list[kStudentCount][kSubjectCount] = {
        {80, 80, 80}, {90, 90, 90}, {95, 95, 95}
    };
    int (*ptr_student)[kSubjectCount] = score_list;
    int summation[kStudentCount] = {};
    int* ptr_summation = summation;
    for (int i = 0; i < kStudentCount; ++i) {
        for (int j = 0; j < kSubjectCount; ++j) {
            *(ptr_summation) += *(*ptr_student + j);
        }
        ptr_summation++;
        ptr_student++;
    }
    ptr_summation = summation;
    for (int idx = 0; idx < kStudentCount; ++idx) {
        std::cout << *(ptr_summation + idx) << ' ';
    }
}

void ReverseSentence() {
    const int kSentenceLength = 100;
    char sentence[kSentenceLength] = {};
    std::cin.getline(sentence, kSentenceLength);
    bool is_in_word = false;
    int word_count = 0, start_position = 0, end_position = 0;
    char* ptr_char = sentence;
    int idx = 0;
    do {
        if (*(ptr_char + idx) != ' ' && is_in_word == false) {
            word_count++;
            is_in_word = true;
            start_position = idx;
        }
        if ((*(ptr_char + idx) == ' ' || *(ptr_char + idx) == '\0') && is_in_word == true) {
            is_in_word = false;
            end_position = idx - 1;
        }
        if (end_position) {
            int n_times = (end_position - start_position) / 2;
            for (int times = 0; times < n_times; ++times) {
                std::swap(*(ptr_char + start_position), *(ptr_char + end_position));
                start_position++;
                end_position--;
            }
        }
        end_position = 0;
        ++idx;
    } while (*(ptr_char + idx - 1) != '\0');
    std::cout << sentence << ' ' << word_count << std::endl;
}

void AnalyzeDynamicArray() {
    int array_length;
    std::cin >> array_length;
    int* array = new int[array_length]();
    for (int idx = 0; idx < array_length; ++idx) {
        std::cin >> *(array + idx);
    }
    int maximum = array[0], summation = 0;
    for (int idx = 0; idx < array_length; ++idx) {
        if (*(array + idx) > maximum) {
            maximum = *(array + idx);
        }
        summation += *(array + idx);
    }
    delete[] array;
    array = nullptr;
    std::cout << maximum << ' ' << summation / array_length << std::endl;
}

void SmartPointer() {
    int array_length;
    std::cin >> array_length;
    std::unique_ptr<int[]> smart_pointer_to_dynamic_array = std::make_unique<int[]>(array_length);
    int* raw_smart_pointer_to_dynamic_array = smart_pointer_to_dynamic_array.get(); //借用裸指针
    for (int idx = 0; idx < array_length; ++idx) {
        int element;
        std::cin >> element;
        *(raw_smart_pointer_to_dynamic_array + idx) = element;
    }
    std::unique_ptr<int[]> smart_pointer_to_dynamic_array_move = std::move(smart_pointer_to_dynamic_array);
    if (smart_pointer_to_dynamic_array == nullptr) {
        std::cout << "Moved already." << '\n';
    } else {
        std::cout << "Didnt move." << '\n';
    }
    int summation = 0, maximum = smart_pointer_to_dynamic_array_move[0];
    for (int idx = 0; idx < array_length; ++idx) {
        summation += smart_pointer_to_dynamic_array_move[idx];
        if (smart_pointer_to_dynamic_array_move[idx] > maximum) {
            maximum = smart_pointer_to_dynamic_array_move[idx];
        }
    }
    std::cout << "Maximum = " << maximum << '\n'
    << "Average = " << summation * 1.0 / array_length << '\n' ;
}

void BinarySearch() {
    const int kArrayLength = 10;
    int array[kArrayLength] = {2, 5, 7, 8, 9, 11, 23, 26, 32, 37};
    int target, target_position;
    if (!(std::cin >> target)) {
        std::cout << "Invalid input." << std::endl;
    }
    bool is_found = false;
    int start_position = 0, end_position = kArrayLength - 1;
    while (start_position <= end_position) {
        int middle_position = (start_position + end_position) / 2;
        if (*(array + middle_position) == target) {
            target_position = middle_position;
            is_found = true;
            break;
        } else if (*(array + middle_position) < target) {
            start_position = middle_position + 1;
        } else {
            end_position = middle_position - 1;
        }
    }
    if (is_found) {
        std::cout << "Find: index " <<  target_position << std::endl;
    } else {
        std::cout << "Not find." << std::endl;
    }
}

void SelectionSort() {
    int array_length;
    std::cout << "Please enter the count of these numbers: ";
    std::cin >> array_length;
    int* array = new int[array_length]();
    for (int idx = 0; idx < array_length; ++idx) {
        std::cin >> *(array + idx);
    }
    for (int i = 0; i < array_length - 1; ++i) {
        int min_index = i;
        for (int j = i; j < array_length - 1; ++j) {
            if (array[j + 1] < array[min_index]) {
               min_index = j + 1;
            }
        }
        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
    for (int idx = 0; idx < array_length; ++idx) {
        std::cout << *(array + idx) << ' ';
    }
    delete[] array;
    array = nullptr;
}

int main() {
    return 0;
}