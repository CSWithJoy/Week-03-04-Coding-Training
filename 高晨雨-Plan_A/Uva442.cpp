//判断能否矩阵运算，不能则报错，可以则计算需要运算多少次乘法，每次遇到右括号弹栈并判断
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
struct Matrices
{
	int l;
	int r;
}M[31];
int main()
{
	int T;
	cin>>T;
	memset(M,0,sizeof(M));
	char ch[2];
	while(T--)
	{
		cin>>ch;
		cin>>M[ch[0]-'A'].l>>M[ch[0]-'A'].r;
	}
	string a;
	stack<Matrices> S;
	while(cin>>a)
	{
		int ans=0,flag=1;
		int len=a.length();
		for(int i=0;i<len;i++)
		{
			if(a[i]=='(') continue;
			else if(a[i]==')')
			{
				M[27].l=S.top().l;
				M[27].r=S.top().r;
				S.pop();
				M[28].l=S.top().l;
				M[28].r=S.top().r;
				S.pop();
				if(M[28].r!=M[27].l)
				{
					flag=0;
					break;
				}
				ans+=M[28].l*M[28].r*M[27].r;
				M[29].l=M[28].l;
				M[29].r=M[27].r;
				S.push(M[29]);
			}
			else S.push(M[a[i]-'A']);
		}
		if(!flag) printf("error\n");
		else printf("%d\n",ans);
	}
	return 0;
}
