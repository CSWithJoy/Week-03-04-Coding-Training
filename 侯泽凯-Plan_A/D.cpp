//水题，试了一下新学的map
#include<bits/stdc++.h>
using namespace std;

struct mat{
	//char id;
	int l,r;
}temp,change;

int main()
{
	map<char,pair<int,int> >p;

	int n;
	cin>>n;
	char idnum;
	int r,c;
	for(int i=0;i<n;i++)
	{
		cin>>idnum>>r>>c;
		p[idnum].first=r;
		p[idnum].second=c;
	}

	string op;
	stack<mat>s;

	while(cin>>op)
	{
		int sum=0;
		int i;
		for(i=0;i<op.length();i++)
		{
			if(op[i]=='(')continue;
			else if(isalpha(op[i]))
			{
				temp.l=p[op[i]].first;
				temp.r=p[op[i]].second;
				s.push(temp);
			}
			else if(op[i]==')')
			{
				temp=s.top();
				s.pop();
				if(s.top().r!=temp.l)
				{
					break;
				}
				sum+=(s.top().l*s.top().r*temp.r);
				temp.l=s.top().l;
				s.pop();
				s.push(temp);
			}
		}
		if(i!=op.length())
		{
			cout<<"error"<<endl;
		}
		else
		{
			cout<<sum<<endl;
		}
	}
	return 0;
}
