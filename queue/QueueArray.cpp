#include <iostream>
using namespace std;

class QueueArray {
private:
    int* data;
    int frontIndex, rearIndex;
    int capacity;
    int count;

public:
    // Constructor
    QueueArray(int size) {
        capacity = size;
        data = new int[capacity];
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    // Add item to rear
    void enqueue(int value) {
        if (count == capacity) {
            cout << "Queue Overflow"<<endl;
            return;
        }

        data[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
    }

    // Remove item from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow"<<endl;
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    // Return front item
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return -1;
        }
        return data[frontIndex];
    }

    // Check if empty
    bool isEmpty() {
        return count == 0;
    }

    // Get current size
    int size() {
        return count;
    }

    // Destructor
    ~QueueArray() {
        delete[] data;
    }
};

// Test the Queue by Array 
int main() {
    QueueArray q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() <<endl;  
    q.dequeue();
    cout << "After dequeue, front: " << q.front() <<endl;  

    return 0;
}
