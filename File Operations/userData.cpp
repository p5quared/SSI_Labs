#include <iostream>
#include <fstream>
#include <string>
/*
 * The goal of this exercise is to create a program that saves a user's name and age to a file, then loads it back.
 * Your user data could be anything, but it should at least store a name and an age.
 */

struct User {
    std::string name;
    int age;
};

void saveUser(const User& user, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << user.name << std::endl;
        outputFile << user.age << std::endl;
        std::cout << "User information saved successfully." << std::endl;
    } else {
        std::cerr << "Error opening the file." << std::endl;
    }

    outputFile.close();
}

User loadUser(const std::string& filename) {
    User user;
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::getline(inputFile, user.name);
        inputFile >> user.age;
        std::cout << "User information loaded successfully." << std::endl;
    } else {
        std::cerr << "Error opening the file." << std::endl;
    }

    inputFile.close();
    return user;
}

int main() {
    User user;
    user.name = "John Doe";
    user.age = 30;

    saveUser(user, "user_info.txt");

    User loadedUser = loadUser("user_info.txt");

    std::cout << "Name: " << loadedUser.name << std::endl;
    std::cout << "Age: " << loadedUser.age << std::endl;

    return 0;
}
