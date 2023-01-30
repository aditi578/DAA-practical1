#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        std::cout << x << " pushed to stack" << std::endl;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << s.pop() << " popped from stack\n";

    std::cout << "Top item is " << s.peek() << std::endl;

    return 0;
}
