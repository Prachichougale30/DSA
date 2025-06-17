#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m = {{1, "Geeks"}, {2, "For"}, {3, "Geeks"}};
    int choice, key;
    string value;

    while (true) {
        cout << "\n----- Map Operations Menu -----\n";
        cout << "1. Insert Element\n";
        cout << "2. Access Element\n";
        cout << "3. Update Element\n";
        cout << "4. Find Element\n";
        cout << "5. Traverse Map\n";
        cout << "6. Delete Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                m.insert({key, value});
                cout << "Inserted: " << key << " " << value << endl;
                break;

            case 2:
                cout << "Enter key to access: ";
                cin >> key;
                if (m.find(key) != m.end())
                    cout << "Value at key " << key << ": " << m[key] << endl;
                else
                    cout << "Key not found.\n";
                break;

            case 3:
                cout << "Enter key and new value to update: ";
                cin >> key >> value;
                if (m.find(key) != m.end()) {
                    m[key] = value;
                    cout << "Updated key " << key << " with value: " << value << endl;
                } else {
                    cout << "Key not found. Cannot update.\n";
                }
                break;

            case 4:
                cout << "Enter key to find: ";
                cin >> key;
                if (m.find(key) != m.end())
                    cout << "Found: " << key << " " << m[key] << endl;
                else
                    cout << "Key not Found!\n";
                break;

            case 5:
                cout << "Traversing map:\n";
                for (auto x : m)
                    cout << x.first << " " << x.second << endl;
                break;

            case 6:
                cout << "Enter key to delete: ";
                cin >> key;
                if (m.erase(key))
                    cout << "Deleted key: " << key << endl;
                else
                    cout << "Key not found. Cannot delete.\n";
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
