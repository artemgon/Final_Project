#include "libs.h"

//Structure for info about product
struct Product {
    string category;
    int quantity;
    double price;
};

// Class to manage the store
class ElectronicsStore {
private:
    map<string, Product> inventory; 

public:

    void addProduct(const string& name, const string& category, int quantity, double price) {
        if (inventory.find(name) != inventory.end()) {
            cout << "Product with name \"" << name << "\" already exists.\n";
            return;
        }
        inventory[name] = { category, quantity, price };
        cout << "Product \"" << name << "\" successfully added.\n";
    }

    void editProduct(const string& name) {
        if (inventory.find(name) == inventory.end()) {
            cout << "Product \"" << name << "\" not found.\n";
            return;
        }

        cout << "Enter new category: ";
        cin.ignore();
        string newCategory;
        getline(cin, newCategory);

        cout << "Enter new quantity: ";
        int newQuantity;
        cin >> newQuantity;

        cout << "Enter new price: ";
        double newPrice;
        cin >> newPrice;

        inventory[name] = { newCategory, newQuantity, newPrice };
        cout << "Product \"" << name << "\" successfully updated.\n";
    }

    void deleteProduct(const string& name) {
        if (inventory.erase(name)) {
            cout << "Product \"" << name << "\" deleted.\n";
        }
        else {
            cout << "Product \"" << name << "\" not found.\n";
        }
    }

    void searchProduct(const string& name) {
        auto it = inventory.find(name);
        if (it != inventory.end()) {
            cout << "Name: " << name << "\nCategory: " << it->second.category
                << "\nQuantity: " << it->second.quantity << "\nPrice: "
                << fixed << setprecision(2) << it->second.price << "\n";
        }
        else {
            cout << "Product \"" << name << "\" not found.\n";
        }
    }

    void displayAllProducts() {
        if (inventory.empty()) {
            cout << "The product list is empty.\n";
            return;
        }

        cout << left << setw(20) << "Name" << setw(15) << "Category"
            << setw(10) << "Quantity" << setw(10) << "Price\n";
        cout << string(55, '-') << "\n";

        for (const auto& [name, product] : inventory) {
            cout << left << setw(20) << name << setw(15) << product.category
                << setw(10) << product.quantity << fixed << setprecision(2) << setw(10)
                << product.price << "\n";
        }
    }

    void calculateTotalValue() {
        double totalValue = 0.0;
        for (const auto& [name, product] : inventory) {
            totalValue += product.quantity * product.price;
        }
        cout << "Total value of products in the store: " << fixed << setprecision(2) << totalValue << "\n";
    }
};
