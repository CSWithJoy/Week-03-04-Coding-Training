/*
dp[l][r],代表l到r的最少回文字串数
dp[l][r]=min(dp[l][r],(k从l到r)min(dp[l][k]+dp[k+1][r]))
预处理一下l->r哪些是回文
因为是从左往右推进 所以可以优化为
if(flag[l][i])
dp[l][r]=min(dp[l][r],1+dfs(i+1,r));
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int t,dp[maxn+10][maxn+10],flag[maxn+10][maxn+10];

char a[maxn+10];

int judge(int l,int r){
     for(int i=l,j=r;i<=j;i++,j--){
        if(a[i]!=a[j]) return 0;
     }
     return 1;
}

int dfs(int l,int r){
   if(dp[l][r]!=inf) return dp[l][r];
   if(l>r) return 0;
   if(flag[l][r]) return 1;
   for(int i=l;i<=r;i++){
        if(flag[l][i])
        dp[l][r]=min(dp[l][r],1+dfs(i+1,r));
   }
   return dp[l][r];
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,inf,sizeof(dp));
        scanf("%s",a+1);
        int lena=strlen(a+1);
        for(int i=1;i<=lena;i++){
                for(int j=i;j<=lena;j++){
                        flag[i][j]=judge(i,j);
                }
        }
        //printf("%d\n",strlen(a+1));
        printf("Case %d: %d\n",h,dfs(1,lena));
    }
    return 0;
}
