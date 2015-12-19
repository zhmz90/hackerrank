#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node* Reverse(Node* head)
{
    Node *tmp,*tmp2,*tg1,*tg2,*nt1,*nt2;
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;

    tg1 = head;
    head->next = NULL;
    tg2 = head->next;
    tmp = tg2;
    if (head->next->next == NULL){
        tg1->prev = tg2;
        tg2->next = tg1;
        tg1->next = tg1;
    }

    return head;
}

int main(){
    Node *nd1,*nd2,*nd3,*head;
    nd1 = new Node;
    nd2 = new Node;
    nd3 = new Node;

    nd1->data = 1;
    nd2->data = 2;
    nd3->data = 3;
    
    nd1->prev = NULL;
    nd1->next = nd2;
    nd2->next = nd3;
    nd2->prev = nd1;
    nd3->prev = nd2;
    nd3->next = NULL;

    head = nd1;

    Reverse(head);

    return 0;
}
