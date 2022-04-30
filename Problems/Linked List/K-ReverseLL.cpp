/**
 * @file L=K-ReverseLL.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a linked list, write a function to reverse every k-nodes (where k is the number of nodes & an input from the function) 
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

node* kReverse(node* head, int k)
{
    node* prev = NULL;
    node* current = head;
    node* temp;
    int cnt = 1;

    while(current!=NULL && cnt<=k)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;

        cnt++;
    }

    if(temp!=NULL)
    {
        head->next = kReverse(temp, k);
    }

    return prev ;
}

int main()
{
    node* head = NULL;
    for(int i=8;i>0;i--)
    {
        insertAtHead(head, i);
    }

    int k;
    cin>>k;

    head = kReverse(head,k);
    printLinkedList(head);
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1->2->3->4->5->6->7->8->NULL
 * 3
 *
 * OUTPUT
 * 3->2->1->6->5->4->8->7->NULL
 * 
 */