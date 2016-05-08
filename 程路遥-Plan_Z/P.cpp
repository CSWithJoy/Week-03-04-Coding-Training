#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=20;
int crime[MAXN];
int mp[MAXN][MAXN];
int dp[(1<<16)+10];
int n;
const int INF=0x3f3f3f3f;
void solve(){
    dp[0]=0;
    int k;
    for(k=0;k<(1<<n)-1;k++){
        for(int i=0;i<n;i++){
            if(!(k&(1<<i))){//还没取,现在要把这个人干掉！
                int sum=INF;//最差情况 平A。。。
                for(int j=0;j<n;j++){
                    if(k&(1<<j)&&mp[j][i]!=0){//找个武器//mb,是j i不是i j
                        int k;                           //用第j个武器杀第i个人需要多少次
                        int m = crime[i] / mp[j][i];
                        k = (crime[i] % mp[j][i]) ? m+1 : m;
                        sum = min(sum, k);
                    }
                }
                if(sum==INF) sum=crime[i];
                dp[k|(1<<i)]=min(dp[k|(1<<i)],dp[k]+sum);
            }
        }
    }
}
int main(){
	int T,nc(1);
	scanf("%d",&T);
	while(T--){
        memset(crime,0,sizeof(crime));
        memset(mp,0,sizeof(mp));
        //getchar();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&crime[i]);
        }
        char du;
        //getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                cin>>du;
                mp[i][j]=du-'0';
            }
            getchar();
        }
        memset(dp,INF,sizeof(dp));
        solve();
        printf("Case %d: %d",nc++,dp[(1<<n)-1]);
	}
	return 0;
}
