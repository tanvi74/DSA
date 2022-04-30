/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Yes, a Linked List may contain a Cycle! See this example below, where the last node instead of pointing to a NULL points to some middle node of the linked list.
 * 
 * E.G; https://img-c.udemycdn.com/redactor/raw/coding_exercise_instructions/2021-05-13_11-29-41-a00f9d52cc891523ee16569cbd4e4c5b.png
 * 
 * Your task is to write a function, that returns true/false depending upon whether the linked contains a cycle or not! 
 * 
 * Hints:
 * Hint - 1 Think 🤔 using Runner Technique - Two Pointers (Fast & Slow)
 * Hint - 2 If they enter inside the loop, they will match at some point.
 * 
 * If you want to break the loop, read about Floyd's Cycle Detection Algorithm.
 */


#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
        int data,flag;
        node* next;

        node(int data)
        {
            this->data = data;
            next = NULL;
            flag = 0;
        }
};

bool containsCycle(node *head)
{
    //Complete this function 
    while(head!=NULL)
    {
        if(head->flag==1)
            return true;
        
        head->flag = 1;
        head = head->next;
    }
    
    return false;
    
}

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
    node* a = NULL;
    cout<<containsCycle(a)<<endl;
    
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1->2->3->4->5
 *       \     |
 *        8-7<-6
 *
 * OUTPUT
 * true
 * 
 */