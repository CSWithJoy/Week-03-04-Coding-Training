//按照给出的顺序查找叶子节点，0代表查找左子树，1代表查找右子树
#include<iostream>
#include<stdio.h>
using namespace std;
#define Max 20000
char NUM[Max], putin[Max];
int a[Max],v[10];
int N;
int solve(int k)
{
	int a=1;
	for(int i=0;i<k;i++)
	{
		if(putin[v[i]]=='0') a*=2;
		else a=(a*2+1);
	}
	if(NUM[a]=='0') return 0;
	return 1;
}
int main()
{
	char s[100];
	int flag=1;
	while(cin>>N,N)
	{
		getchar();
		gets(s);
		int q=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]!=' '&&s[i]!='x') v[q++]=s[i]-'1';
		}
		gets(NUM);
		int ans=1;
		for(int i=1;i<=N;i++) ans*=2;
		for(int i=0;i<ans;i++)
		{
			NUM[ans+i]=NUM[i];
		}
		int t;
		cin>>t;
		getchar();
		for(int i=0;i<t;i++)
		{
			gets(putin);
			a[i]=solve(N);
		}
		printf("S-Tree #%d:\n",flag);
		flag++;
		for(int i=0;i<t;i++) cout<<a[i];
		cout<<endl<<endl;
	}
	return 0;
}
