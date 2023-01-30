#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *next;
    int data;

    node(int val)
    {
        data = val;
        this->next = NULL;
    }
};
void InsertHead(node *&head, int n)
{
    node *temp = head;
    node *x = new node(n);
    x->next = head;
    head = x;
}

void InsertTail(node *&head, int n)
{
    node *temp = head;
    node *x = new node(n);
    if (head == NULL)
    {
        head = x;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = x;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;
    InsertHead(head,1);
    InsertHead(head,2);
    InsertHead(head , 3);
    InsertHead(head,4);
    InsertHead(head,5);
    InsertTail(head,6);
    InsertTail(head,7);
    display(head);
    


    return 0;
}