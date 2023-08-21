#include <iostream>
#include <vector>
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

    // Display the adjacency list
    void display() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " -> ";
            Node* current = adjList[i];
            while (current != nullptr) {
                cout << current->vertex << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 5;
    AdjacencyList graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Adjacency List:" << endl;
    graph.display();

    return 0;
}

