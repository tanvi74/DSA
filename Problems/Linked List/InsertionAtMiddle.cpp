/**
 * @file InsertionAtMiddle.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Inserting node in the middle in a linked list
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

void insertAtMiddle(node* &head, int data, int pos)
{
    if(pos==0)
    {
        insertAtHead(head, data);
    }
    else
    {
        node* temp = head;
        for(int jump=0; jump<pos; jump++)
        {
            temp = temp->next;
        }

        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }

    return;
}

int main()
{
    node* head = NULL;

    int data,pos;
    cin>>data;
    cin>>pos;

    insertAtMiddle(head, data, pos);

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