
/**
 * @file PhoneNumberSearch.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * You are given a Android Phone smart keypad which looks exactly like the one shown below. No, its not the regular phone keypad problem! 😉
 * 
 * As we can see every digit is associated with some letters, for example 2 is mapped with (a,b,c). This allowes certain phone numbers to be mapped with actual words. For example - the phone number 666 can be written as mom or moo. Similarly, 7728335 can be written as prateek or something other string as well. Hence, a given phone number can represent multiple possible strings.
 * 
 * You are given a phone number (as a string input) and a non-empty list of words. Write a function that returns the list of words that can be found in the phone number. The final list can contain words in any order. (Yes, we will use sorting at the backend to compare your result with ours😉)
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
            char data;
            unordered_map<char,Node*> m;
            bool isTerminal;

            Node(char d)
            {
                data = d;
                isTerminal = false;
            }
};

class Trie
{
    Node *root;
    public:
            Trie()
            {
                root = new Node('\0');
            }

            void insert(string word)
            {
                Node* temp = root;
                for(char ch : word)
                {
                    if(temp->m.count(ch)==0)
                    {
                        Node *n = new Node(ch);
                        temp->m[ch] = n;
                    }
                    temp = temp->m[ch];
                }

                temp->isTerminal = true;
            }

            bool search(string word)
            {
                Node* temp = root;
                for(char ch : word)
                {
                    if(temp->m.count(ch)==0)
                    {
                        return false;
                    }
                    temp = temp->m[ch];
                }

                return temp->isTerminal;
            }
};

int main()
{
    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 7728335
 * 6
 * prat prateek codingminutes code prat335 teek
 * 
 * OUTPUT
 * prat prateek teek
 * 
 */


