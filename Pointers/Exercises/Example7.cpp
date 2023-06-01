#include <iostream>

struct Student {
    std::string name;
    int age;
    char grade;
};

int main() {
    Student* studentPtr = new Student;

    std::cout << "Enter student name: ";
    std::cin >> studentPtr->name;

    std::cout << "Enter student age: ";
    std::cin >> studentPtr->age;

    std::cout << "Enter student grade: ";
    std::cin >> studentPtr->grade;

    std::cout << "Student Details:" << std::endl;
    std::cout << "Name: " << studentPtr->name << std::endl;
    std::cout << "Age: " << studentPtr->age << std::endl;
    std::cout << "Grade: " << studentPtr->grade << std::endl;

    delete studentPtr;

    return 0;
}
