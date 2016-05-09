//不同的在线建树方法
#include<bits/stdc++.h>
using namespace std;

#define maxn 100

int sum[maxn];

void build(int p)
{
	int v;
	cin>>v;
	if(v==-1)
	{
		return;
	}
	sum[p]+=v;
	build(p-1);
	build(p+1);
}

bool init()
{
	int v;
	cin>>v;
	if(v==-1)
	{
		return false;
	}
	memset(sum,0,sizeof(sum));
	int pos=maxn/2;
	sum[pos]=v;
	build(pos-1);
	build(pos+1);
}

int main()
{
	int z=1;
	while(init())
	{
		int p=0;
		while(sum[p]==0)p++;
		printf("Case %d:\n",z++);
		cout<<sum[p++];
		while(sum[p]!=0)
		{
			cout<<" "<<sum[p++];
		}
		cout<<endl<<endl;
	}
	return 0;
}
