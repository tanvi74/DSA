/**
 * @file Search.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Searching in a linked list
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

bool isPresent(node * head, int key)
{    
    node* current = head;
    while(current != NULL)
    {
        if(current->data == key)
        {
            return true;
        }
        current = current->next;
    }
    
    return false;
}

int main()
{
    node* head = new node(1);
    node* first = new node(2);
    node* second = new node(3);

    head->next = first;
    first->next = second;

    int key;
    cin>>key;

    cout<<isPresent(head, key)<<endl;
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