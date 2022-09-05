
/**
 * @file SuffixTrie.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
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

class SuffixTrie
{
    Node *root;
    public:
            SuffixTrie()
            {
                root = new Node('\0');
            }

            void insert_helper(string word)
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

            void insert(string word)
            {
                // pick all substrings 
                for(int i=0; i!=word[i]!='\0'; i++)
                {
                    insert_helper(word.substr(i));
                }
            }
};

int main()
{
    string input = "hello";

    SuffixTrie st;
    st.insert(input);

    string suffixes[] = {"lo", "elo", "hello"};

    for(auto ch:suffixes)
    {
        if(st.search(ch))
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
 *
 * 
 * OUTPUT
 * YES
 * NO
 * YES
 *  
 */


