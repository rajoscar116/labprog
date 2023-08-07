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

    Node* getHead() const {
        return head;
    }

    void setHead(Node* newHead) {
        head = newHead;
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

class Stack {
private:
    LinkedList list;

public:
    // Function to push a new element onto the stack
    void push(int value) {
        list.insert(value);
    }

    // Function to pop an element from the stack
    void pop() {
        // In a singly linked list, removing the last element requires traversing the list
        // to reach the last node. This can be improved by using a doubly linked list or
        // by adding a tail pointer to the existing singly linked list class.
        if (!isEmpty()) {
            Node* current = list.getHead();
            Node* prev = nullptr;
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            if (prev != nullptr) {
                prev->next = nullptr;
            } else {
                list.setHead(nullptr);
            }

            delete current;
        }
    }

    // Function to get the top element of the stack
    int peek() {
        if (!isEmpty()) {
            Node* current = list.getHead();
            while (current->next != nullptr) {
                current = current->next;
            }
            return current->data;
        }
        // You can handle this case differently based on your use case,
        // like throwing an exception or returning a specific value to indicate an empty stack.
        std::cout << "Stack is empty!" << std::endl;
        return -1; // Return -1 for simplicity (Assuming stack doesn't contain negative values)
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return list.getHead() == nullptr;
    }

    // Function to clear the stack and free memory
    void clear() {
        list.clear();
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.peek() << std::endl;

    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    stack.clear();

    return 0;
}
