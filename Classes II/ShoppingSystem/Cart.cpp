#include "cart.h"
#include <iostream>

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