#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class AdjacencyList {
private:
    struct Node {
        int vertex;
        Node* next;
    };

    vector<Node*> adjList;
    int numVertices;

public:
    // Constructor
    AdjacencyList(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices, nullptr);
    }

    // Add an edge between two vertices
    void addEdge(int source, int destination) {
        if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
            Node* newNode = new Node();
            newNode->vertex = destination;
            newNode->next = adjList[source];
            adjList[source] = newNode;
        } else {
            cout << "Invalid vertices." << endl;
        }
    }

    // Breadth-First Search
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Search starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            Node* current = adjList[currentVertex];
            while (current != nullptr) {
                int neighbor = current->vertex;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
                current = current->next;
            }
        }

        cout << endl;
    }
};



