#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Returns the index of the parent node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Returns the index of the left child
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Returns the index of the right child
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Moves the element at index i up to maintain heap property
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Moves the element at index i down to maintain heap property
    void heapifyDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Inserts a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Returns the minimum value (root of the heap)
    int getMin() {
        if (heap.empty()) {
            cout<<"Heap is empty"<<endl;
        }
        return heap[0];
    }

    // Removes and returns the minimum value
    void extractMin() {
        if (heap.empty()) {
            cout<<"Heap is empty"<<endl;
        }

        // Replace root with the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property
        heapifyDown(0);
    }

    // Displays all elements of the heap
    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Returns true if heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

// Test The MinHeap
int main() {
    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(30);
    minHeap.insert(3);
    minHeap.insert(8);

    cout << "Heap elements: ";
    minHeap.display();

    cout << "Minimum value: " << minHeap.getMin() << endl;

    minHeap.extractMin();
    cout << "After extracting min, heap: ";
    minHeap.display();

    return 0;
}
