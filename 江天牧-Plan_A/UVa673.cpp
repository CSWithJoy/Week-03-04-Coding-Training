//水题
#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
char s_str[130];
int main()
{
    int T;
    cin >> T;
    getchar();
    while(T--)
    {
        gets(s_str);
        int s_lence = strlen(s_str);
        stack<char> st_str;
        int flag = 1;
        for(int i = 0; i < s_lence; i++)
        {
            if(s_str[i] == '(' || s_str[i] == '[')
            {
                st_str.push(s_str[i]);
            }
            else
            {
                if(s_str[i] == ')')
                {
                    if(st_str.empty())
                    {
                        flag = 0;
                        break;
                    }
                    if(st_str.top() == '(')
                    {
                        st_str.pop();
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                else
                {
                    if(st_str.empty())
                    {
                        flag = 0;
                        break;
                    }
                    if(st_str.top() == '[')
                    {
                        st_str.pop();
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag && st_str.empty())
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
}
