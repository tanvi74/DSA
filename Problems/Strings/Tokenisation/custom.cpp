/** 
 * Tokenisation a string denotes splitting a string h respect to some delimiter(s)
 **/

#include<bits/stdc++.h>
using namespace std;

char *mystrok (char *S, char delim )
{
    static char *input = NULL;
    if(S!=NULL)
    {
        input = S;
    }
    
    if(input==NULL)
        return NULL;

    char *token = new char[strlen(input)+1];
    int i=0;
    
    for(;input[i]!='\0';i++)
    {
        if(input[i]==delim)
        {
            token[i]='\0';
            input = input + i + 1;
            return token;
        }
        else
        {
            token[i] = input[i];
        }
    }

    token[i] = '\0';
    input = NULL;
    return token;
} 

int main()
{
    char S[1000];
    cin.getline(S,1000);

    char *token = mystrok(S, ' ');

    while(token!=NULL)
    {
        cout<<token<<endl;
        token = mystrok(NULL,' ');
    }

}

/**
 * @brief 
 * Input
 * today is a sunny day
 * 
 * 
 * Output
 * today
 * is 
 * a 
 * sunny
 * day
 * 
 * 
 */