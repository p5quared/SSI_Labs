#include "cart.h"
#include <iostream>
#include <fstream>
#include <sstream>


void Cart::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Failed to open file for writing." << std::endl;
        return;
    }

    for (const auto& product : products) {
        file << product.getName() << "," << product.getPrice() << "," << product.getQuantity() << std::endl;
    }

    file.close();
    std::cout << "Cart saved to file: " << filename << std::endl;
}

void Cart::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Failed to open file for reading." << std::endl;
        return;
    }

    products.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::string name;
        float price;
        int quantity;

        // Parse the line and extract the name and price
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        iss >> price;
        iss >> quantity;

        if (!iss.fail()) {
            Product product(name, price, quantity);
            products.push_back(product);
        }
    }

    file.close();
    std::cout << "Cart loaded from file: " << filename << std::endl;
}

void Cart::addProduct(const Product& product) {
    products.push_back(product);
}

void Cart::removeProduct(const std::string& name) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == name) {
            products.erase(it);
            break;
        }
    }
}

void Cart::checkout() {
    double totalPrice = 0.0;
    for (const auto& product : products) {
        product.getDetails();
        totalPrice += product.getPrice();
    }
    std::cout << "Total Price: $" << totalPrice << std::endl;

    products.clear();
}

float Cart::getTotal() const {
    float total = 0.0;
    for (const auto& product : products) {
        total += product.getPrice();
    }
    return total;
}

void Cart::empty() {
    products.clear();
}
