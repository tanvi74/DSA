/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Recusively Reversing linked list
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

node* recReverse( node* head)
{
    // base case
    if(head==NULL or head->next===NULL)
    {
        return head;
    }

    node *shead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return shead; 
} 

int main()
{
    node* head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    head = recReverse(head);
    cout<<"RECURSIVE LINKED LIST:"<<endl;
    printLinkedList(head);

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 
 *
 * OUTPUT
 * 0
 * 1
 * 2
 * 3
 * 4
 * 
 */