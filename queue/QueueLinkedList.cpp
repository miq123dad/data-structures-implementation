#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class QueueLinkedList {
private:
    Node* frontNode;
    Node* rearNode;

public:
    // Constructor
    QueueLinkedList() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    // Add value to rear
    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};

        if (rearNode == nullptr) { 
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // Remove from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow"<<endl;
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
    }

    // Get front value
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return -1;
        }

        return frontNode->data;
    }

    // Check if empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Destructor
    ~QueueLinkedList() {
        while (!isEmpty())
            dequeue();
    }
};

// Test the Queue by LinkedList
int main() {
    QueueLinkedList q;

    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);

    cout << "Front: " << q.front() <<endl;  
    q.dequeue();
    cout << "After dequeue, front: " << q.front() <<endl; 

    return 0;
}
