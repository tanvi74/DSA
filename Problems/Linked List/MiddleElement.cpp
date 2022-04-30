/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Find middle element of the linked list 
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

int getMid(node *head){
    //Complete this function to return data middle node
    node* fast = head;
    node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next;
        if(fast->next != NULL)
            slow = slow->next;
            
        fast = fast->next;
    }
    
    return slow->data;
}


int main()
{
    node* a = NULL;

    for(int i=8;i>0;i--)
    {
        insertAtHead(a,i);
    }

    int c = getMid(a);
    cout<<c<<endl;
    
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1->2->3->4->5->6->7->8->NULL
 *
 * OUTPUT
 * 4
 * 
 */