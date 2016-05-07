//求每个水平位置的落叶总数，用一位数组存储，lch为x-1,rch为x+1
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 500
int sum[maxn];
int pos;
void build(int p)
{
	int v;
	cin>>v;
	if(v==-1) return;//递归
	sum[p]+=v;
	build(p-1);
	build(p+1);
}
bool init()
{
	int v;
	cin>>v;
	if(v==-1) return false;
	memset(sum,0,sizeof(sum));
	int pos=maxn/2;
	sum[pos]=v;
	build(pos-1);
	build(pos+1);
}
int main()
{
	int kase=0;
	while(init())
	{
		int p=0;
		while(sum[p]==0) p++;
		printf("Case %d:\n",++kase);
		printf("%d",sum[p++]);
		while(sum[p]!=0) printf(" %d",sum[p++]);
		printf("\n\n");
	}
	return 0;
}
