#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[35];
long long shuwei[40];
long long len;
long long dp[40][40][2];
long long n;
void ini(){
    len=0;
    memset(shuwei,0,sizeof(shuwei));
    memset(dp,-1,sizeof(dp));
    while(n){
        shuwei[++len]=n%2;
        n/=2;
    }
    //cout<<len<<endl;
    getchar();
}
//判断边界这里需要学习一下。。。多多找dp做做。。。
long long jia(long long now,long long cnt,long long pre,bool flag){
    long long res=0;
    if(!now) return cnt;
    if(flag&&dp[now][cnt][pre]!=-1) return dp[now][cnt][pre];
    long long du;
    if(!flag) du=shuwei[now];
    else du=1;
    long long i;
    for(long long i=0;i<=du;i++){
        if(pre==1&&i==1)
            res+=jia(now-1,cnt+1,i,flag||i<du);
        else
            res+=jia(now-1,cnt,i,flag||i<du);
    }
    if(flag) dp[now][cnt][pre]=res;
    return res;
}
int main(){
	int T,nc=1;
	scanf("%d",&T);
	int i;
	while(T--){
        scanf("%d",&n);
        ini();
        printf("Case %d: %lld\n",nc++,jia(len,0,-1,0));
	}
	return 0;
}
