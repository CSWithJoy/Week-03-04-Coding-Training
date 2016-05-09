//记忆化搜索+状态转移
//把问题细化成区间[i,j]里是否存在回文串，然后DP解决
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 1010
char str[N];
int dp[N];
int cas=1;
bool judge(int i,int j)
{
	while(i<=j)
	{
		if(str[i]!=str[j]) return false;
		i++;
		j--;
	}
	return true;
}
void DP()
{
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		dp[i]=INF;
		for(int j=0;j<=i;j++)
		{
			if(judge(j,i))
			{
				if(j==0) dp[i]=1;
				else dp[i]=min(dp[i],dp[j-1]+1);
			}
		}
	}
	printf("Case %d: %d\n",cas++,dp[len-1]);
}
int main()
{
	int T;
	cin>>T;
	while(T--) DP();
	return 0;
}
