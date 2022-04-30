/**
 * @file Kth-LastElement.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Implement a function that returns the Kth last of element from the linked list, in a single pass. You can assume K will be less than / equal to length of linked list.
 * 
 * (Hint : Use two pointers similar to Runner Technique)
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

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    
    node* fast_ptr = head;
    node* slow_ptr = head;
    
    for (int i = 1; i < k; i++) 
    {
            fast_ptr = fast_ptr->next;
    }
     
    while(fast_ptr!=NULL && fast_ptr->next!=NULL)
    {
        fast_ptr = fast_ptr->next;

        slow_ptr = slow_ptr->next;
    }
    
    return slow_ptr->data;
   
}


int main()
{
    node* a = NULL;

    for(int i=8;i>0;i--)
    {
        insertAtHead(a,i);
    }

    int c = kthLastElement(a, 3);
    cout<<c<<endl;
    
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1->2->3->4->5->6->7->NULL
 * 3
 * 
 * OUTPUT
 * 5
 * 
 */