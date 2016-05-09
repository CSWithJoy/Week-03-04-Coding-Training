//括号匹配
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char c;
		stack<char>sl;
		stack<char>sr;

		while((c=getchar())!='\n')
		{
			if( c=='(' || c=='[' )
			{
				sl.push(c);
			}
			else if( c==')' || c==']' )
			{
				if(!sl.empty() &&( (sl.top()=='('&&c==')') || (sl.top()=='['&&c==']') ))
				{
					sl.pop();
				}
				else
				{
					sr.push(c);
				}
			}
		}
		if(sl.empty()&&sr.empty())
		{
			printf("Yes\n");//cout<<""<<endl;
		}
		else
		{
			printf("No\n");//cout<<""<<endl;
		}
		while(!sl.empty())
		{
			sl.pop();
		}
		while(!sr.empty())
		{
			sr.pop();
		}
	}
	return 0;
}
