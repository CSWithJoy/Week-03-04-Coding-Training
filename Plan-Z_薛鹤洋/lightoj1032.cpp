/*
数位dp模板题，如果有两个连续的1，就计数。
第一位前面没有数 所以初始pre=0;
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,h,a[maxn+10];

long long dp[maxn+10][2][maxn+10];

long long dfs(int pos,int pre,int status,int limit){
     if(pos<0) return status;
     if(!limit&&dp[pos][pre][status]!=-1) return dp[pos][pre][status];
     int end=limit?a[pos]:1;
     long long ret=0;
     for(int i=0;i<=end;i++){
        if(i&&pre){
                ret+=dfs(pos-1,i,status+1,limit&&i==end);
        } else {
                ret+=dfs(pos-1,i,status,limit&&i==end);
        }
     }
     if(!limit) dp[pos][pre][status]=ret;
     return ret;
}

void solve(){
   memset(a,0,sizeof(a));
   memset(dp,-1,sizeof(dp));
   int len=0;
   while(n){
        a[len++]=n%2;
        n/=2;
   }
   printf("Case %d: %lld\n",h,dfs(len-1,0,0,1));
}

int main()
{
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(h=1;h<=t;h++){
        scanf("%d",&n);
        solve();
    }
    return 0;
}
