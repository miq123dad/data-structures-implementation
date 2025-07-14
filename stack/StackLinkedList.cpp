#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;     // The value stored
    Node* next;   // Pointer to the next node
};

// Stack class using Linked List
class StackLinkedList {
private:
    Node* topNode;  

public:
    // Constructor
    StackLinkedList() {
        topNode = nullptr; 
    }

    // Push a value onto the stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = topNode;  
        topNode = newNode;      
    }

    // Pop the top value from the stack
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow (empty stack)"<<endl;
            return;
        }

        Node* temp = topNode;    
        topNode = topNode->next;
        delete temp;              
    }

    // Return the top value without removing it
    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty"<<endl;
            return -1;
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Destructor to clean up memory
    ~StackLinkedList() {
        while (!isEmpty()) {
            pop(); 
        }
    }
};

// Example usage
int main() {
    StackLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() <<endl; 

    stack.pop(); 

    cout << "Top after pop: " << stack.top() <<endl; 

    stack.pop();
    stack.pop();
    stack.pop();  

    return 0;
}

