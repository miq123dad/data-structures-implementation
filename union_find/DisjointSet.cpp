#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent; 
    vector<int> rank;   
public:
    // Constructor: initialize each element as its own parent
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0); 
        for (int i = 0; i < size; ++i)
            parent[i] = i; 
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; 
        // Attach smaller tree under the root of the larger tree
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++; 
        }
    }

    // Check if two elements are in the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

//  Test the DisjointSet 

int main() {
    DisjointSet ds(7); 

    ds.unite(0, 1);
    ds.unite(1, 2);
    ds.unite(3, 4);
    ds.unite(5, 6);
    ds.unite(4, 5);

    cout << boolalpha;
    cout << "0 connected to 2? " << ds.isConnected(0, 2) << endl;
    cout << "3 connected to 6? " << ds.isConnected(3, 6) << endl;
    cout << "0 connected to 4? " << ds.isConnected(0, 4) << endl;

    ds.unite(2, 4); 

    cout << "Now 0 connected to 4? " << ds.isConnected(0, 4) << endl;

    return 0;
}
