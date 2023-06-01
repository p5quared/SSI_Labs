#include "customer.h"
#include <iostream>

Customer::Customer(const std::string& name) : name(name) {}

void Customer::viewProducts(const std::vector<Product>& products) const {
    std::cout << "Available Products:" << std::endl;
    for (const auto& product : products) {
        product.getDetails();
        std::cout << std::endl;
    }
}

void Customer::addToCart(const std::string& name, const std::vector<Product>& products, Cart& cart) {
    for (const auto& product : products) {
        if (product.getName() == name) {
            cart.addProduct(product);
            std::cout << "Product added to cart." << std::endl;
            return;
        }
    }
    std::cout << "Product not found." << std::endl;
}

void Customer::removeFromCart(const std::string& name, Cart& cart) {
    cart.removeProduct(name);
}

void Customer::checkout(Cart& cart) {
    cart.checkout();
}
