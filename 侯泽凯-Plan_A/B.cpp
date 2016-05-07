//扫一遍比较不同顺序即可
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		stack<string>ori;
		stack<string>tar;
		string temp;
		int n;
		cin>>n;

			getchar();
			for(int i=0;i<n;i++)
			{
				getline(cin,temp);
				ori.push(temp);
			}
			for(int i=0;i<n;i++)
			{
				getline(cin,temp);
				tar.push(temp);
			}
			while(!ori.empty())
			{
				if(ori.top()==tar.top())
				{
					ori.pop();
					tar.pop();
				}
				else
				{
					ori.pop();
				}
			}
			while(!tar.empty())
			{
				cout<<tar.top()<<endl;
				tar.pop();
			}

		cout<<endl;
	}
	return 0;
}
