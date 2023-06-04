//
// Created by Peter Vaiciulis on 5/31/23.
//

#include "Customer.h"

Customer::Customer(const std::string& name) : name(name) {}

void Customer::viewProducts(const std::vector<Product>& products) const {
    std::cout << "Products:" << std::endl;
    for (const auto& product : products) {
        std::cout << product.getName() << " - $" << product.getPrice() << std::endl;
    }
}

void Customer::addToCart(const std::string& name, const std::vector<Product>& products, Cart& cart) {
    for (const auto& product : products) {
        if (product.getName() == name) {
            cart.addProduct(product);
            return;
        }
    }
    std::cout << "Product not found." << std::endl;
}

void Customer::removeFromCart(const std::string& name, Cart& cart) {
    cart.removeProduct(name);
}

void Customer::checkout(Cart& cart) {
    std::cout << "Total: $" << cart.getTotal() << std::endl;
    cart.empty();
}