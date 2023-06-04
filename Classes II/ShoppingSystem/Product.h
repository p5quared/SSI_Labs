#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
public:
    Product(const std::string& name, double price, int quantity);

    void getDetails() const;

    std::string getName() const;
    double getPrice() const;

private:
    std::string name;
    double price;
    int quantity;
};

#endif  // PRODUCT_H
