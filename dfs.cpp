#include <iostream>
#include <vector>
#include <stack>
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

    // Depth-First Search
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        s.push(startVertex);

        cout << "Depth-First Search starting from vertex " << startVertex << ": ";

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            Node* current = adjList[currentVertex];
            while (current != nullptr) {
                int neighbor = current->vertex;
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
                current = current->next;
            }
        }

        cout << endl;
    }
};


