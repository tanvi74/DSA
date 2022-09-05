
/**
 * @file GooglyStrings.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * Prateek bhaiya while working at Google often encounters string problems, so this time he is asking for your help to solve this problem. You are given a list of non-empty strings and you have to return a list of all "Googly" strings found in the input list.
 * A string is said to be Googly if it is exactly made up of atleast two instances of other string in the input list of strings.
 * In order for a string to be googly, just containing two instances of other strings isn't sufficient, the string be exactly made up of those strings. For example, in the list ["a", "b", "abc"] the string "abc" isn't googly, even though it contains "a" and "b", but "c" isn't a string in the list.
 * 
 * Note that strings can be repeated to form a special string; for example in the list ["a","aaa"], the string "aaa" is a Googly string because it is made up of three repeated instances of "a"
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


