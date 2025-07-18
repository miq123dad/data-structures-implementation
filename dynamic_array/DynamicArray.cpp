#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;      // Pointer to the dynamic array
    int capacity;   // Total allocated memory size
    int size;       // Current number of elements

    // Doubles the capacity and copies existing elements
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];

        for (int i = 0; i < size; i++) {
            newData[i] = data[i]; 
        }

        delete[] data; 
        data = newData; 
    }

public:
    // Constructor to initialize the array
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    // Add an element at the end
    void push(int value) {
        if (size == capacity) 
            resize();
        data[size++] = value;
    }

    // Remove the last element
    void pop() {
        if (size > 0)
            size--;
    }

    // Get the element at a specific index
    int get(int index) {
        if (index >= 0 && index < size) 
            return data[index];
        else {
            cout << "Index is out of bounds" << endl;
            return -1; 
        }
    }

    // Return current number of elements
    int getSize() {
        return size;
    }

    // Destructor to clean up memory
    ~DynamicArray() {
        delete[] data;
    }
};

// Test The Dynamic Array
int main() {
    DynamicArray arr;

    arr.push(10);
    arr.push(20);
    arr.push(30);

    cout << "Array contents: ";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;

    arr.pop();

    cout << "After pop: ";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;

    return 0;
}
