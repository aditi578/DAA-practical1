#include <iostream>

struct Node {
  int data;
  Node* next;
};

class Queue {
 private:
  Node* front;
  Node* rear;
 public:
  Queue() : front(nullptr), rear(nullptr) {}
  void enqueue(int data);
  int dequeue();
  bool is_empty();
};

void Queue::enqueue(int data) {
  Node* temp = new Node;
  temp->data = data;
  temp->next = nullptr;
  if (rear == nullptr) {
    front = rear = temp;
    return;
  }
  rear->next = temp;
  rear = temp;
}

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  while (!q.is_empty()) {
    std::cout << q.dequeue() << std::endl;
  }
  return 0;
}
