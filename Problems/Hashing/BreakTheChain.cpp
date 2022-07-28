
/**
 * @file BreakTheChain.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a linked list which contains a cycle, build a hashing based algorithm to break the cycle and return the head of the linked list, the last node should point to NULL after breaking the cycle. 
 * Note - it is not guaranteed that each element of the linked node is unique, so decide hashing key accordingly.
 * 
 * Input
 * Head of the linked List
 * 
 * Output
 * Head of the linked list after breaking the cycle
 * 1->2->3->4->5->NULL
 * 
 * Note
 * You may use node address as the key.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head)
 {
     //Complete this method
     unordered_map<node*,bool> Ti;
     
     node*current = head;
     node*prev = head;
     
     while(Ti.find(head) == Ti.end())
     {
         Ti[head] = true;
         prev = head;
         head = head->next;
     }
     
     prev->next = NULL;
     
     return current;
 }

int main()
{
    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 *
 * 
 * OUTPUT
 * 
 * 
 */


