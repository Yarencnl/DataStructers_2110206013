//9.  DFS, BFS uygulaması
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<list<int>> adj; 

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS (Baslangic: " << startNode << "): ";

        while (!q.empty()) {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int startNode) {
        vector<bool> visited(V, false);
        cout << "DFS (Baslangic: " << startNode << "): ";
        DFSUtil(startNode, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.BFS(0);
    g.DFS(0);

    return 0;
}