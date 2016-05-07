//Water
#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int T,n,nn;
	string name;
	cin>>T;
	stack<string> aim;
	stack<string> putin;
	while(T--)
	{
		cin>>n;
		getchar();
		nn=n;
		while(nn--)
		{
			getline(cin,name);
			putin.push(name);
		}
		while(n--)
		{
			getline(cin,name);
			aim.push(name);
		}
		while(!putin.empty())
		{
			if(putin.top()==aim.top())
			{
				putin.pop();
				aim.pop();
			}
			else putin.pop();
		}
		while(!aim.empty())
		{
			cout<<aim.top()<<endl;
			aim.pop();
		}
		cout<<endl;
	}
	return 0;
}
