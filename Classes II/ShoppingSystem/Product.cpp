#include "Product.h"

Product::Product(const std::string& name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

void Product::getDetails() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

