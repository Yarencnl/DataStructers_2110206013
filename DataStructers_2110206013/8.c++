// 8.  Array olarak verilen bir graph’da cluster çıkarma.
#include <iostream>
#include <vector>

using namespace std;

#define V 7 

void DFS(int graph[V][V], int v, bool visited[], vector<int>& cluster) {
    visited[v] = true;
    cluster.push_back(v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, cluster);
        }
    }
}

void findClusters(int graph[V][V]) {
    bool visited[V] = {false};
    int clusterCount = 0;

    cout << "--- Graf Kümeleri ---" << endl;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            clusterCount++;
            vector<int> currentCluster;
            
            DFS(graph, i, visited, currentCluster);

            cout << "Küme " << clusterCount << ": ";
            for (int node : currentCluster) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
    cout << "\nToplam bulunan küme sayısı: " << clusterCount << endl;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0} 
    };

    findClusters(graph);

    return 0;
}