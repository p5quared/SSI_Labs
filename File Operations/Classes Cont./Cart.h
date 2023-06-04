#ifndef CART_H
#define CART_H

#include <vector>
#include "product.h"

class Cart {
public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& name);
    float getTotal() const;
    void checkout();
    void empty();

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Product> products;
};

#endif  // CART_H
