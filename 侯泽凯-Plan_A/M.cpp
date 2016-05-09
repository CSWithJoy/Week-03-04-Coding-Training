//数位dp 后面加一维表示前一位
//完全手打一边题解。。。弱爆了orz
#include<bits/stdc++.h>
using namespace std;

const int maxn=40;
typedef long long LL;
int N;

int dig[maxn];
LL dp[maxn][maxn][2];

LL dfs(int cur,int s,int e,int last)
{
    if(cur<0)
		return s;

    if(e==0 && dp[cur][s][last]!=-1)
	{
		return dp[cur][s][last];
	}

    LL ans=0;

    int end=(e!=0 ? dig[cur]:1 );

    for(int i=0;i<=end;i++)
    {
        if(last&&i)
		{
			ans+=dfs(cur-1,s+1,e&&i==end,i);
		}
        else
		{
			ans+=dfs(cur-1,s,e&&i==end,i);
		}
    }
    if(e==0)
	{
		dp[cur][s][last]=ans;
	}
    return ans;
}

LL solve(int n)
{
    int len=0;

    memset(dp,-1,sizeof(dp));

    while(n)
    {
        dig[len++]=n%2;//化n为二进制
        n/=2;//写成>>会不匹配
    }
    return dfs(len-1,0,1,0);
}

int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("Case %d: %lld\n",cas++,solve(N));
    }
    return 0;
}
