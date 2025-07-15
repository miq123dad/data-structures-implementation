#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Circular Singly Linked List
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* prev = nullptr;
        Node* temp = head;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    // Print the list
    void printList() {
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";

        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
                cout << " → ";
        } while (temp != head);

        cout << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }
};

// Test the Circular LinkedList 
int main() {
    CircularLinkedList clist;

    clist.insertAtEnd(10);
    clist.insertAtEnd(20);
    clist.insertAtEnd(30);
    clist.printList();  

    clist.insertAtBeginning(5);
    clist.printList();  

    clist.deleteFromBeginning();
    clist.printList();

    clist.deleteFromEnd();
    clist.printList(); 

    return 0;
}
