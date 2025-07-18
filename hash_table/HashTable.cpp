#include <iostream>
#include <list>
using namespace std;


class HashTable {
private:
    static const int TABLE_SIZE = 10; 
    list<pair<int, string>> table[TABLE_SIZE]; 

    // Hash function to map key to index
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Insert key-value pair into hash table
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        // Check if key already exists and update
        for (auto& element : table[index]) {
            if (element.first == key) {
                element.second = value;
                return;
            }
        }
        // Insert new key-value pair
        table[index].push_back({key, value});
    }

    // Remove key-value pair by key
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
        cout << "Key " << key << " not found"<<endl;
    }

    // Search for value by key
    string search(int key) {
        int index = hashFunction(key);
        for (const auto& element : table[index]) {
            if (element.first == key)
                return element.second;
        }
        return "Key not found";
    }

    // Print the entire hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            for (const auto& element : table[i]) {
                cout << "(" << element.first << ", " << element.second << ") -> ";
            }
            cout << "NULL"<<endl;
        }
    }
};

// Test The Hash Table
int main() {
    HashTable ht;

    ht.insert(1, "One");
    ht.insert(2, "Two");
    ht.insert(12, "Twelve"); 
    ht.insert(22, "Twenty-Two");

    ht.display();

    cout << "Search for key 12: " << ht.search(12) << endl;
    cout << "Search for key 5: " << ht.search(5) << endl;

    ht.remove(2);
    cout << "After removing key 2:"<<endl;
    ht.display();

    return 0;
}
