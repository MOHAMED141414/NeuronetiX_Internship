#ifndef SHOPPINGCARTSYSTEM_H_INCLUDED
#define SHOPPINGCARTSYSTEM_H_INCLUDED

#include <string>
#include <vector>
using namespace std;
// Product Class
class Product {
private:
    string name;
    string description;
    double price;
    int stockQuantity;

public:
    // Constructor
    Product(const string& name, const string& description, double price, int stockQuantity);

    // Getter methods
    string getName() const;
    string getDescription() const;
    double getPrice() const;
    int getStockQuantity() const;

    // Update stock
    void updateStock(int quantity);
};

// Cart Class
class Cart {
private:
    vector<Product> items;
    vector<int> quantities;

public:
    // Add or remove items from cart
    void addItem(const Product& product, int quantity);
    void removeItem(const Product& product);
    void updateQuantity(const Product& product, int newQuantity);

    // Calculate total cost
    double calculateTotal() const;

    // View cart items
    void viewCart() const;
};

// User Class
class User {
private:
    string username;
    Cart cart;

public:
    // Constructor
    User(const string& username);

    // Get user's cart
    Cart& getCart();

    // Get user information
    string getUsername() const;
};

// Order Class
class Order {
private:
    User& user;
    Cart& cart;
    string paymentStatus;
    string shippingDetails;

public:
    // Constructor
    Order(User& user, Cart& cart);

    // Process payment
    void processPayment(const string& paymentMethod);

    // Confirm order
    void confirmOrder();

    // Display order summary
    void displayOrderSummary() const;
};



#endif // SHOPPINGCARTSYSTEM_H_INCLUDED
