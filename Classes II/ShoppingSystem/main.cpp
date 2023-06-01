#include <iostream>
#include <vector>
#include "product.h"
#include "cart.h"
#include "customer.h"

int main() {
    // Create some sample products
    std::vector<Product> products;
    products.emplace_back("Product 1", 10.99, 5);
    products.emplace_back("Product 2", 19.99, 3);
    products.emplace_back("Product 3", 7.99, 8);

    // Create a cart and a customer
    Cart cart;
    Customer customer("John");

    // Display available products
    customer.viewProducts(products);

    // Add products to the cart
    customer.addToCart("Product 1", products, cart);
    customer.addToCart("Product 3", products, cart);

    // Remove a product from the cart
    customer.removeFromCart("Product 1", cart);

    // Checkout and place the order
    customer.checkout(cart);

    return 0;
}
