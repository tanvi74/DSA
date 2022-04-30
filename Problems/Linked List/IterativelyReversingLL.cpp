/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Iterative Reversing linked list
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

void reverse(node* &head)
{
    node* prev = NULL;
    node* current = head;
    node* temp;

    while(current!=NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    head = prev;
    return;
}

int main()
{
    node* head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    cout<<"RECURSIVE LINKED LIST:"<<endl;
    reverse(head);

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 
 *
 * OUTPUT
 * RECURSIVE LINKED LIST:
 * 0
 * 1
 * 2
 * 3
 * 4
 * 
 */