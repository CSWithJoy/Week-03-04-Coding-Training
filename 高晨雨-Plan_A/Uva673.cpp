//Water
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<char>lkuohao;
	int T,flag;
	char ch;
	cin>>T;
	getchar();
	while(T--)
	{
		flag=0;
		while(!lkuohao.empty()) lkuohao.pop();
		while((ch=getchar())!='\n')
		{
			//if(ch=='\n') break;
			if(ch=='('||ch=='[') lkuohao.push(ch);
			else if(lkuohao.empty()&&(ch==']'||ch==')')) lkuohao.push(ch);
				else if(ch==']'&&lkuohao.top()=='[') lkuohao.pop();
					 else if(ch==')'&&lkuohao.top()=='(') lkuohao.pop();
		}
		if(lkuohao.empty()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
