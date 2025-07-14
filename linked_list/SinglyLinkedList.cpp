#include <iostream>
using namespace std;

// Definition of a Node in the linked list
struct Node {
    int data;     // Stores the value   
    Node* next;   // Pointer to the next node  
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head; 

public:
    // Constructor: initialize the list as empty
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node;  
        newNode->data = value;     
        newNode->next = head;     
        head = newNode;           
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        // If list is empty, new node becomes the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Link last node to new node
        temp->next = newNode;
    }

    // Delete the first node in the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is already empty"<<endl;
            return;
        }

        Node* temp = head;  
        head = head->next;  
        delete temp;         
    }

    // Print all elements in the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ? ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }

    // Destructor: clean up all nodes when object is destroyed
    ~SinglyLinkedList() {
        while (head != nullptr) {
            deleteFromBeginning(); 
    }
};

};

// Test the Singly Linked List
int main() {
    SinglyLinkedList list;

  
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);  

    list.insertAtEnd(40);       

    cout << "Current List: ";
    list.printList();

    list.deleteFromBeginning();  

    cout << "After deleting from beginning: ";
    list.printList();

    return 0;
}


