//顺序是关键
#include<bits/stdc++.h>
using namespace std;

int to[10];
int op[10];
int leave[1<<9];
int output[1<<9];
int cnt;

int main()
{
	int n;
	cnt=1;
	while(cin>>n,n)
	{
		printf("S-Tree #%d:\n",cnt++);
		char x;
		int id;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>id;
			op[id]=i;
			to[i]=id;
		}

		string temp;
		cin>>temp;
		for(int i=0;i<temp.length();i++)
		{
			leave[i]=temp[i]-'0';
		}

		int ball;
		cin>>ball;

		for(int i=0;i<ball;i++)
		{
			string path;
			cin>>path;
			int des=1;
			for(int k=1;k<=path.length();k++)
			{
				if(path[to[k]-1]=='0')
				{
					des*=2;
				}
				else if(path[to[k]-1]=='1')
				{
					des=des*2+1;
				}
			}
			cout<<leave[des-(1<<n)];
		}
		cout<<endl<<endl;
	}
	return 0;
}
