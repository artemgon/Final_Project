#include "logic(core).h"

int main()
{
    ElectronicsStore store;
    string command;

    while (true) {
        cout << "\nSelect an action:\n1. Add product\n2. Edit product\n3. Delete product\n"
            << "4. Search for product\n5. Show all products\n6. Calculate total value\n7. Exit\nYour choice: ";
        cin >> command;

        if (command == "1") {
            string name, category;
            int quantity;
            double price;

            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter category: ";
            getline(cin, category);

            cout << "Enter quantity: ";
            cin >> quantity;

            cout << "Enter price: ";
            cin >> price;

            store.addProduct(name, category, quantity, price);

        }
        else if (command == "2") {
            string name;
            cout << "Enter product name to edit: ";
            cin.ignore();
            getline(cin, name);
            store.editProduct(name);

        }
        else if (command == "3") {
            string name;
            cout << "Enter product name to delete: ";
            cin.ignore();
            getline(cin, name);
            store.deleteProduct(name);

        }
        else if (command == "4") {
            string name;
            cout << "Enter product name to search: ";
            cin.ignore();
            getline(cin, name);
            store.searchProduct(name);

        }
        else if (command == "5") {
            store.displayAllProducts();

        }
        else if (command == "6") {
            store.calculateTotalValue();

        }
        else if (command == "7") {
            cout << "Goodbye!\n";
            break;

        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
	return 0;
}