
/**
 * @file LittleCuteCat.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 * Little cute kitten love to write stories in a Githu b readme doc. One day she is given a list of wrods, you want to help her out to check if each of words are present in the readme file. 
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
    public:
            Node *root;
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
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m)
{
    Node* temp = t.root;

    for(int j = i; j<document.length; j++)
    {
        char ch = document[j];
        if(temp->children.count(ch)==0)
        {
            return;
        }

        temp = temp->children[ch];
        if(temp->isTerminal)
        {
            // history part
            string out = document.substr(i, j-i+1);
            m[out] = true;
        }
    }

    return;
}

void documentSearch(string document, vector<string>words)
{
    // 1. Create trie for words
    Trie t;
    for(auto w: words)
    {
        t.insert(w);
    }

    // 2. Searching Helper function
    unordered_map<string, bool> m;

    for(int i=0;i<document.length();i++)
    {
        searchHelper(t, document, i, m);
    }

    // 3. check which words are marked as true in map
    for(auto w: words)
    {
        cout<<w<<" ";
        if(m[w])
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }

}

int main()
{
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat", "ttle", "cat", "quick", "big"};



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


