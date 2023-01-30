#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtFront(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        std::cout << x << " inserted at front" << std::endl;
    }

    void insertAtBack(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        std::cout << x << " inserted at back" << std::endl;
    }

    int deleteAtFront() {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return -1;
        }
        int x = head->data;
        Node* temp = head;
        if (head->next != nullptr) {
            head->next->prev = nullptr;
        }
        head = head->next;
        delete temp;
        return x;
    }

    int deleteAtBack() {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return -1;
        }
        int x;
        if (head->next == nullptr) {
            x = head->data;
            delete head;
            head = nullptr;
            return x;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        x = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return x;
    }

    void printList() {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(){


  DoublyLinkedList list;

    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtBack(3);

    std::cout << list.deleteAtBack() << " deleted from back";
    return 0;

    }