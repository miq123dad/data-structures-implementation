#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
private:
    // Adjacency list: each node has a list of neighbors
    unordered_map<int, vector<int>> adjList;
    bool directed;

public:
    // Constructor (by default: undirected graph)
    Graph(bool isDirected = false) {
        directed = isDirected;
    }

    // Add an edge between u and v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    // Display the adjacency list
    void printGraph() {
        for (auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Check if the graph contains a node
    bool containsNode(int node) {
        return adjList.find(node) != adjList.end();
    }
};

int main() {
    
    Graph g(false);  // false = undirected

   
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    
    cout << "Adjacency List:" << endl;
    g.printGraph();

    return 0;
}
