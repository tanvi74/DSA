/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Inserting node at the start in a linked list
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

int main()
{
    node* head = NULL;

    int data;
    cin>>data;

    insertAtHead(head, data);
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 3
 *
 * OUTPUT
 * yes
 * 
 */