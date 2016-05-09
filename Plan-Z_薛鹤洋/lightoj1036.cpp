/*
对于某一个点来说，如果这个点往上，则上方所有点一直往上，这个点往左，左边所有点都往左。
以3*3的矩形为例，
1 1 ↑
1 1 ↑
1 1 ↑

1 1 1
1 1 1
← ← ←

这个矩形所能运输的最大值，是max(2*2+(3,3)点向上, 2*2+(3,3)向左)

dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+b[i][j]);

*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=500;

using namespace std;

int t,v,n,m,a[maxn+10][maxn+10],b[maxn+10][maxn+10],dp[maxn+10][maxn+10];

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&v),a[i][j]=a[i][j-1]+v;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&v),b[i][j]=b[i-1][j]+v;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+b[i][j]);
        printf("Case %d: %d\n",h,dp[n][m]);
    }
    return 0;
}
