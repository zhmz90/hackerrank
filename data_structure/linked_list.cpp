#include<iostream>

using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};

Node* Insert(Node *head, int data)
{
    Node *nd;
    nd->data = data;
    nd->next = NULL;

    if (head == NULL)
        return nd;
    Node* tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = nd;

    return head;
}
    

int main() {
    cout<< (1 == 2 || 2 == 2)<<endl;

    /*
    Node * nd = new Node;
    nd->data = 1;
    nd->next = NULL;
    nd->data = 1;
    nd->next = NULL;
    */
    return 0;
}
