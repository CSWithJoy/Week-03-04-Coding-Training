//简单DP，两种矿石，一种只能向北取，一种只能向西取，一个格子如果选定一个方向就只能向一个方向走
//状态转移方程dp[i][j]=max(dp[i-1][j]+w[i][j],dp[i][j-1]+n[i][j])
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int dp[505][505],w[505][505],n[505][505];
int main()
{
	int q,T,r,c;
	cin>>T;
	int kcase=1;
	while(T--)
	{
		cin>>r>>c;
		memset(w,0,sizeof(w));
		memset(n,0,sizeof(n));
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>q;
				w[i][j]=w[i][j-1]+q;
			}
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>q;
				n[i][j]=n[i-1][j]+q;
			}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				dp[i][j]=max(dp[i-1][j]+w[i][j],dp[i][j-1]+n[i][j]);
			}
		printf("Case %d: %d\n",kcase,dp[r][c]);
		kcase++;
	}
	return 0;
}
