#include <iostream>
using namespace std;

class StackArray {
private:
    int* stack;       // Pointer to the stack array
    int topIndex;     // Index of the top element
    int capacity;     // Maximum size of the stack

public:
    // Constructor
    StackArray(int size) {
        capacity = size;
        stack = new int[capacity];
        topIndex = -1; 
    }

    // Push a new value onto the stack
    void push(int value) {
        if (topIndex >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        stack[++topIndex] = value;
    }

    // Pop the top value from the stack
    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;  
    }

    // View the top value without removing it
    int top() {
        if (topIndex < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stack[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Return current size of stack
    int size() {
        return topIndex + 1;
    }

    // Destructor
    ~StackArray() {
        delete[] stack;
    }
};

// Test the Stack using Array
int main() {
    StackArray st(5);  

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << "\n";  

    st.pop();
    cout << "After pop, top: " << st.top() << "\n";  

    cout << "Stack size: " << st.size() << "\n";

    st.pop();
    st.pop();
    st.pop();

    return 0;
}
