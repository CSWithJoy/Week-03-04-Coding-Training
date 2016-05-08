#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N=16;
int t;
int n;
int target[MAX_N];    //目标i 的血量
int p[MAX_N][MAX_N];  //p[i][j]武器i 对 敌人j 的 伤害
int dp[1<<MAX_N];
string s[MAX_N];
void solve(){
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int s=0;s<(1<<n)-1;s++){
        for(int i=0;i<n;i++){
            if(!(s&(1<<i))){
                int t=INF;                             //把第i个人杀死需要多少次
                for(int j=0;j<n;j++){
                    if(s&(1<<j)&&p[j][i]!=0){
                        int k;                           //用第j个武器杀第i个人需要多少次
                        int m=target[i]/p[j][i];
                        k=(target[i]%p[j][i])?m+1:m;
                        t=min(t, k);
                    }
                }
                if(t==INF) t=target[i];              //如果不能用敌人的武器杀，只有用攻击力为1的武器杀
                dp[s|(1<<i)]=min(dp[s|(1<<i)], dp[s]+t);
            }
        }
    }
    printf("%d\n", dp[(1<<n)-1]);
}
int main(){
    scanf("%d", &t);
    int cnt = 1;
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d",&target[i]);
        }
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=s[i][j]-'0';
            }
        }
        printf("Case %d: ", cnt++);
        solve();
    }
    return 0;
}
