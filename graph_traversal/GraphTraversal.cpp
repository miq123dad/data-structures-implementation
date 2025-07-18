#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj;

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add an edge (undirected graph)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Helper (recursive)
    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    // DFS Traversal
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS starting from node " << start << ": ";
        dfsUtil(start, visited);
        cout << endl;
    }

    // BFS Traversal
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from node " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

//  Test the Graph 

int main() {
    Graph g(6); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.DFS(0); // Depth First Search
    g.BFS(0); // Breadth First Search

    return 0;
}
