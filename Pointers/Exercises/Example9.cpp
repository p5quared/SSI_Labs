#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    char line[256];
    while (inputFile.getline(line, sizeof(line))) {
        std::cout << line << std::endl;
    }

    inputFile.close();

    return 0;
}
