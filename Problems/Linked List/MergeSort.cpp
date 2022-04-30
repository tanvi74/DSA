/**
 * @file MergeSort.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a Linked List, WAF to sort the LL using Merge Sort 
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

node* midPoint(node *head)
{

    node* fast = head;
    node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next;
        if(fast->next != NULL)
            slow = slow->next;
            
        fast = fast->next;
    }
    
    return slow;
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

node* mergeSort(node* head)
{
    // BASE 
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    // Rec
    node* mid = midPoint(head);

    // Break at mid
    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    // Recursive Sort
    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);

}

int main()
{
    node* a = NULL;
    node* c = NULL;

    insertAtHead(a,7);
    insertAtHead(a,8);
    insertAtHead(a,4);
    insertAtHead(a,5);
    insertAtHead(a,6);
    insertAtHead(a,1);
    insertAtHead(a,2);
    insertAtHead(a,3);

    c = merge(a,b);

    printLinkedList(c);
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 3->2->1->6->5->4->8->7->NULL
 *
 * OUTPUT
 * 1->2->3->4->5->6->7->8->NULL
 * 
 */