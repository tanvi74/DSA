/**
 * @file SimplifyPath.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * In this coding challenge, we will build a functionality for a command line tool. We want to write a function that takes in a non-empty string representing a valid Unix-shell path and returns a simplified version of the path. The simplified path must be equivalent to the original path, that means it should point to same file/directory as the original path.
 * 
 * A path can be an absolute path, meaning that it starts at the root directory in a file system, or a relative path, meaning that it starts at the current directory in a file system. In a Unix-like Operating System, a path is bounded by the following rules:
 * -> The root directory is represented by a /. This means that if a path start with /, it's an absolute path; if it doesn't, it's a relative path.
 * -> The symbol / otherwise represent the directory separator. This means that the path /x/y is location of directory y inside directory x, which is itself located inside the root directory.
 * -> The symbol .. represents the parent directory. This means that accessing files or directories in /x/y/.. is equivalent to accessing files or directories in /x.
 * -> They symbol . represents the current directory. This means that accessing files or directories in /x/y/. is equivalent to accessing files or directories in /x/y
 * 
 * 
 *  The symbols / and . can be repeated sequentially without consequence; the symbol .. cannot, however repeating it sequentially means going further up in the parent directories. For example,   /x/y/z/././.
 */


#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string S)
{
   // Tokenisation
    istringstream iss(S);
    vector<string> tokens;

    string token;
    while(getline(iss, token, '/'))
    {
        if(token=="." || token=="")
            continue;
        
        tokens.push_back(token);
    }

    vector<string>stack;

    // Absolute path
    if(S[0]=='/')
    {
        stack.push_back("");
    }

    for(auto token : tokens)
    {
        if(token==".." )
        {
            // Relative path
            if(stack.size()==0 || stack[stack.size()-1]=="..")
            {
                stack.push_back(token);
            }
            // To pop everything except the null which is inserted at the first place
            else if(stack[stack.size()-1]!="")
            {
                stack.pop_back();
            }
        }
        else
        {
            stack.push_back(token);
        }
    }

    // Single element
    if(stack.size()==1 && stack[stack.size()-1] == "")
        return "/";

    ostringstream oss;
    int i=0;

    for(auto ele : stack)
    {
        if(i!=0)
            oss<<"/";

        i++;

        oss<<ele;
    }

    return oss.str();
   
}

int main()
{
    string S;
    cin>>S;

    cout<<simplifyPath(S)<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * /a/./b/../../c/
 * /a/..
 * /a///b
 * /a/../
 * /../../../../../a
 * /a/./b/./c/./d/
 * /a/../.././../../.
 *
 * OUTPUT
 * /c
 * /
 * /a/b
 * /
 * /a
 * /a/b/c/d
 * /
 * 
 */