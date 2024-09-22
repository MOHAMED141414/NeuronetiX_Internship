#include "ShoppingCartSystem.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to display product catalog
void displayCatalog(const vector<Product>& products) {
    cout << "\nProduct Catalog:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].getName() << " - $" << products[i].getPrice()
                  << " (" << products[i].getStockQuantity() << " in stock)"<<endl;
    }
}

// Function to get a valid user input for integers
int getValidIntInput() {
    int input;
    while (!(cin >> input)) {
        cin.clear(); // clear invalid input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter a valid number: ";
    }
    return input;
}

int main() {
    // Creating products
    Product product1("Laptop", "A high-end gaming laptop", 1500.0, 10);
    Product product2("Phone", "Latest smartphone with 5G", 999.99, 20);
    Product product3("Headphones", "Noise-cancelling headphones", 199.99, 15);

    vector<Product> products = {product1, product2, product3};

    // Creating a user
    string username;
    cout << "Enter your name: ";
    getline(cin, username);
    User user(username);

    int choice;
    bool shopping = true;

    while (shopping) {
        cout << "\n--- Online Shopping Cart System ---"<<endl;
        cout << "1. View Product Catalog"<<endl;
        cout << "2. Add Item to Cart"<<endl;
        cout << "3. Remove Item from Cart"<<endl;
        cout << "4. View Cart"<<endl;
        cout << "5. Update Quantity in Cart"<<endl;
        cout << "6. Checkout"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        choice = getValidIntInput();

        switch (choice) {
            case 1: {  // View Product Catalog
                displayCatalog(products);
                break;
            }
            case 2: {  // Add Item to Cart
                displayCatalog(products);
                cout << "Enter the product number to add to your cart: ";
                int productNumber = getValidIntInput();

                if (productNumber > 0 && productNumber <= products.size()) {
                    Product& selectedProduct = products[productNumber - 1];
                    cout << "Enter quantity: ";
                    int quantity = getValidIntInput();
                    if (quantity > 0 && quantity <= selectedProduct.getStockQuantity()) {
                        user.getCart().addItem(selectedProduct, quantity);
                        cout << quantity << " " << selectedProduct.getName() << "(s) added to your cart."<<endl;
                    } else {
                        cout << "Invalid quantity."<<endl;
                    }
                } else {
                    cout << "Invalid product number."<<endl;
                }
                break;
            }
            case 3: {  // Remove Item from Cart
                user.getCart().viewCart();
                cout << "Enter the product number to remove from your cart: ";
                int productNumber = getValidIntInput();
                if (productNumber > 0 && productNumber <= products.size()) {
                    Product& selectedProduct = products[productNumber - 1];
                    user.getCart().removeItem(selectedProduct);
                    cout << selectedProduct.getName() << " removed from your cart."<<endl;
                } else {
                    cout << "Invalid product number."<<endl;
                }
                break;
            }
            case 4: {  // View Cart
                user.getCart().viewCart();
                break;
            }
            case 5: {  // Update Quantity in Cart
                user.getCart().viewCart();
                cout << "Enter the product number to update quantity: ";
                int productNumber = getValidIntInput();
                if (productNumber > 0 && productNumber <= products.size()) {
                    Product& selectedProduct = products[productNumber - 1];
                    cout << "Enter new quantity: ";
                    int newQuantity = getValidIntInput();
                    if (newQuantity > 0 && newQuantity <= selectedProduct.getStockQuantity()) {
                        user.getCart().updateQuantity(selectedProduct, newQuantity);
                        cout << "Quantity updated to " << newQuantity << "."<<endl;
                    } else {
                        cout << "Invalid quantity."<<endl;
                    }
                } else {
                    cout << "Invalid product number."<<endl;
                }
                break;
            }
            case 6: {  // Checkout
                Order order(user, user.getCart());
                order.displayOrderSummary();

                cout << "\nProceed with payment? (1 = Yes, 0 = No): ";
                int paymentChoice = getValidIntInput();
                if (paymentChoice == 1) {
                    order.processPayment("Credit Card");
                    order.confirmOrder();
                } else {
                    cout << "Checkout cancelled."<<endl;
                }
                break;
            }
            case 7: {  // Exit
                shopping = false;
                cout << "Thank you for shopping, " << user.getUsername() << "!"<<endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again."<<endl;
                break;
            }
        }
    }

    return 0;
}
