/*
设dp[x]为从1-n的期望移动 a[i]为x的因子
dp[x]=(dp[a[1]]+1)/c+(dp[a[2]]+1)/c....+dp[a[c]]+1/c
移项后即为答案
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100000;

using namespace std;

int t,n;

double dp[maxn+10];

double dfs(int x){
    if(dp[x]!=-1) return dp[x];
    int cnt=2;
    double ans=0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
                cnt++;
                ans+=dfs(x/i);
                if(x/i!=i){
                        cnt++;
                        ans+=dfs(i);
                }
        }
    }
    return dp[x]=(ans+cnt)/(cnt-1);
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        scanf("%d",&n);
        for(int i=2;i<=n;i++) dp[i]=-1;
        dp[1]=0;
        printf("Case %d: %f\n",h,dfs(n));
    }
    return 0;
}
