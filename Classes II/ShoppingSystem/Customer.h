#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include "cart.h"

class Customer {
public:
    Customer(const std::string& name);

    void viewProducts(const std::vector<Product>& products) const;
    void addToCart(const std::string& name, const std::vector<Product>& products, Cart& cart);
    void removeFromCart(const std::string& name, Cart& cart);
    void checkout(Cart& cart);

private:
    std::string name;
};

#endif  // CUSTOMER_H
