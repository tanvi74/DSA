
/**
 * @file PrefixTrie.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a list of string and Q queries, each query containing a word, you have to tell if htat word is in the list or not.
 * 
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
    stirng words = ["apple", "ape", "news", "no", "mango"];
    string S;
    
    Trie t;
    for(auto w: words) 
    {
        t.insert(w);
    }

    int q;
    cin>>q;

    while(q--)
    {
        cin>>S;
        if(t.search(S))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4
 * apple
 * india
 * news
 * new
 * 
 * OUTPUT
 * yes
 * no
 * yes
 * no
 * 
 * 
 */


