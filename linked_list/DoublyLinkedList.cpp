#include <iostream>
using namespace std;

// Node of the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, head};

        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;  

        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, tail, nullptr};

        if (tail != nullptr)
            tail->next = newNode;
        else
            head = newNode;  

        tail = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr; 

        delete temp;
    }

    // Print list from head to tail
    void printForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }

    // Print list from tail to head
    void printBackward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " <- ";
            temp = temp->prev;
        }
        cout << "NULL"<<endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head != nullptr)
            deleteFromBeginning();
    }
};

// Test the Doubly LinkedList
int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtEnd(5);
    dll.insertAtEnd(1);

    dll.printForward();
    dll.printBackward();

    dll.deleteFromBeginning();
    dll.deleteFromEnd();

    dll.printForward();
    dll.printBackward();

    return 0;
}
