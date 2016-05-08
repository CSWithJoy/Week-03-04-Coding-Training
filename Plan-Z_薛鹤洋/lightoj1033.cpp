/*
dp[i][j] 代表从i到j的区间需要补充几个字符能够成回文，
如果 a[i]=a[j] 则 dp[i][j]=dp[i+1][j-1];
else dp[i][j]=min(dp[i+1][j],dp[i][j+1])+1;
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,dp[maxn+10][maxn+10];

char a[maxn+10];

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        scanf("%s",a);
        int len=strlen(a);
        for(int i=len-1;i>=0;i--){
                for(int j=i+1;j<len;j++){
                        if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1];
                        else dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
                }
        }
        printf("Case %d: %d\n",h,dp[0][len-1]);
    }
    return 0;
}
