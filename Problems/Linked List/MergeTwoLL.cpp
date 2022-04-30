/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Merge two linked list in a sorted manner
 * 
 */


#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            next = NULL;
        }
};

void insertAtHead(node* &head, int data)
{
    if(head == NULL)
    {
        head = new node(data);
        return;
    }

    node *n = new node(data);
    n->next = head;
    head = n;

    return;
}

void printLinkedList (node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }

    return;
}

node* merge(node* a, node* b)
{
    // Base Case
    if(a == NULL)
    {
        return b;
    }
    else if(b == NULL)
    {
        return a;
    }

    // Rec Case
    node *c;
    
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a,b->next);
    }

    return c;
}

int main()
{
    node* a = NULL;
    node* b = NULL;
    node* c = NULL;

    insertAtHead(a,10);
    insertAtHead(a,7);
    insertAtHead(a,5);
    insertAtHead(a,1);

    insertAtHead(b,6);
    insertAtHead(b,3);
    insertAtHead(b,2);

    c = merge(a,b);

    printLinkedList(c);
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1->5->7->10->NULL
 * 2->3->6->NULL
 *
 * OUTPUT
 * 1->2->3->5->6->7->10->NULL
 * 
 */