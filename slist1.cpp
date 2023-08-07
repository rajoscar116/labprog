#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to display the contents of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to delete a node with a given value from the list
    void remove(int value) {
        if (head == nullptr)
            return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data != value) {
                current = current->next;
            }
            if (current->next != nullptr) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    // Function to check if a value exists in the list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to clear the list and free memory
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    list.remove(20);
    list.display();

    std::cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 40: " << (list.search(40) ? "Found" : "Not Found") << std::endl;

    list.clear();

    return 0;
}
