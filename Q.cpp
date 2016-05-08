#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=100010;
double dp[MAXN];
void ini(){
    int i;
    for(i=2;i<MAXN;i++){
        double sum=0;
        int k=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                sum+=dp[j];
                k++;
                sum+=dp[i/j];
                k++;
            }
            if(j*j==i){
                sum-=dp[j];
                k--;
            }
        }
        dp[i]=(sum+k)/(k-1);
    }
    /*for(int i=0;i<100;i++)
        cout<<dp[i]<<endl;*/
}
int main(){
	int T,nc(1),n;
	memset(dp,0,sizeof(dp));
	scanf("%d",&T);
	ini();
	while(T--){
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",nc++,dp[n]);
	}
	return 0;
}
