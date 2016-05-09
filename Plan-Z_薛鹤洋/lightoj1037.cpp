/*
用 n==16,可以压缩状态，dp[x]代表杀死x状态的人需要的最少射击，
dp[x]=min(dp[x],dp[x-(1<<i)]+min(杀死i所需的射击));
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,ph[maxn+10],a[maxn+10][maxn+10],dp[(1<<16)+10];

char b[maxn+10];

int dfs(int x){
    //if(x==0) printf("1\n");
    if(dp[x]!=-1) return dp[x];
    dp[x]=inf;
    for(int i=0;i<n;i++){
        if((1<<i)&x) {
              int y=inf;
              for(int j=0;j<n;j++){
                if((1<<j)&(x-(1<<i))&&a[j][i]!=0){
                 int t=ph[i]/a[j][i];
                 if((ph[i]%a[j][i])!=0) t++;
                 y=min(y,t);
                //printf("%d\n",y);
                }
              }
              if(y==inf) y=ph[i];
              dp[x]=min(dp[x],dfs(x-(1<<i))+y);
        }
    }
    return dp[x];
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(dp,-1,sizeof(dp)),memset(ph,0,sizeof(ph));;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&ph[i]);
        }
        for(int i=0;i<n;i++){
           scanf("%s",b);
           for(int j=0;j<n;j++){
                a[i][j]=b[j]-'0';
           }
        }
        dp[0]=0;
        printf("Case %d: %d\n",h,dfs((1<<n)-1));
    }
    return 0;
}
