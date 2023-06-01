## Exercise: Online Shopping System

You are tasked with creating a simple online shopping system using C++ classes. The system should allow users to browse products, add them to a shopping cart, and place orders. Each product has a name, price, and quantity available.

Your task is to design and implement the following classes:

1. **Product**: A class representing a product, with the following attributes and methods:
   - Attributes:
     - `name` (string): the name of the product.
     - `price` (double): the price of the product.
     - `quantity` (int): the quantity available of the product.
   - Methods:
     - `getDetails()`: a method that prints the details of the product.

2. **Cart**: A class representing a shopping cart, with the following attributes and methods:
   - Attributes:
     - `products` (vector of Product objects): a collection of products added to the cart.
   - Methods:
     - `addProduct(Product product)`: a method that adds a product to the cart.
     - `removeProduct(string name)`: a method that removes a product from the cart based on its name.
     - `checkout()`: a method that prints the total price of the products in the cart and empties the cart.

3. **Customer**: A class representing a customer, with the following attributes and methods:
   - Attributes:
     - `name` (string): the name of the customer.
     - `cart` (Cart object): the shopping cart for the customer.
   - Methods:
     - `viewProducts(vector<Product> products)`: a method that displays the available products for the customer to browse.
     - `addToCart(string name, vector<Product> products)`: a method that adds a product to the customer's cart based on its name.
     - `removeFromCart(string name)`: a method that removes a product from the customer's cart based on its name.
     - `checkout()`: a method that allows the customer to checkout and place the order.

Implement the classes and write a program that demonstrates the functionality of the online shopping system. The program should allow the user to interactively perform the following actions:

1. Display the available products.
2. Add products to the cart.
3. Remove products from the cart.
4. Checkout and place the order.

#### Make use of advanced features such as inheritance, virtual functions, operator overloading, and templates where applicable to enhance the design and functionality of your classes.
