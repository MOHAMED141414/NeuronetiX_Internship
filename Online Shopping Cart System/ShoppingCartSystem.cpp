#include "ShoppingCartSystem.h"
#include <iostream>

using namespace std;
// Product Class Implementation
Product::Product(const string& name, const string& description, double price, int stockQuantity)
    : name(name), description(description), price(price), stockQuantity(stockQuantity) {}

string Product::getName() const {
    return name;
}

string Product::getDescription() const {
    return description;
}

double Product::getPrice() const {
    return price;
}

int Product::getStockQuantity() const {
    return stockQuantity;
}

void Product::updateStock(int quantity) {
    stockQuantity -= quantity;
}

// Cart Class Implementation
void Cart::addItem(const Product& product, int quantity) {
    items.push_back(product);
    quantities.push_back(quantity);
}

void Cart::removeItem(const Product& product) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getName() == product.getName()) {
            items.erase(items.begin() + i);
            quantities.erase(quantities.begin() + i);
            break;
        }
    }
}

void Cart::updateQuantity(const Product& product, int newQuantity) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getName() == product.getName()) {
            quantities[i] = newQuantity;
            break;
        }
    }
}

double Cart::calculateTotal() const {
    double total = 0.0;
    for (size_t i = 0; i < items.size(); ++i) {
        total += items[i].getPrice() * quantities[i];
    }
    return total;
}

void Cart::viewCart() const {
     cout << "Cart Items: "<<endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << items[i].getName() << " - " << quantities[i] << " pcs"<<endl;
    }
    cout << "Total: $" << calculateTotal() <<endl;
}

// User Class Implementation
User::User(const string& username)
    : username(username) {}

Cart& User::getCart() {
    return cart;
}

string User::getUsername() const {
    return username;
}

// Order Class Implementation
Order::Order(User& user, Cart& cart)
    : user(user), cart(cart), paymentStatus("Pending"), shippingDetails("Not set") {}

void Order::processPayment(const string& paymentMethod) {
    cout << "Processing payment via " << paymentMethod << "..."<<endl;
    paymentStatus = "Paid";
}

void Order::confirmOrder() {
     cout << "Order confirmed for " << user.getUsername() << "!"<<endl;
    shippingDetails = "Order will be shipped soon.";
}

void Order::displayOrderSummary() const {
    cout << "Order Summary:"<<endl;
    cart.viewCart();
    cout << "Payment Status: " << paymentStatus<<endl;
    cout << "Shipping Details: " << shippingDetails <<endl;
}
