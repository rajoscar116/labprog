include <iostream>

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

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

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
    Stack() {}

    void push(int value) {
        list.insert(value);
    }

    void pop() {
        // Since the provided linked list implementation does not have a tail pointer,
        // we will iterate through the list to find the last element for popping.
        if (!list.isEmpty()) {
            Node* current = list.getHead();
            Node* prev = nullptr;
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }
            if (prev != nullptr) {
                prev->next = nullptr;
            } else {
                list.clear(); // If the stack had only one element, clear the list to empty the stack.
            }
            delete current;
        }
    }

    int peek() {
        if (!list.isEmpty()) {
            Node* current = list.getHead();
            while (current->next != nullptr) {
                current = current->next;
            }
            return current->data;
        }
        std::cout << "Stack is empty!" << std::endl;
        return -1; // Return -1 for an empty stack (Assuming stack doesn't contain negative values)
    }

    bool isEmpty() {
        return list.isEmpty();
    }

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
