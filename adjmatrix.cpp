#include <iostream>
using namespace std;

const int maxSize = 100; // Maximum number of vertices in the graph

class AdjacencyMatrix {
private:
    int matrix[maxSize][maxSize];
    int numVertices;

public:
    // Constructor
    AdjacencyMatrix(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                matrix[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    // Add an edge between two vertices
    void addEdge(int source, int destination) {
        if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
            matrix[source][destination] = 1;
            matrix[destination][source] = 1; // For an undirected graph
        } else {
            cout << "Invalid vertices." << endl;
        }
    }

    // Display the adjacency matrix
    void display() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 5;
    AdjacencyMatrix graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Adjacency Matrix:" << endl;
    graph.display();

    return 0;
}

