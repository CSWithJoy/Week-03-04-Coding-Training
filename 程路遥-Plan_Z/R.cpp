#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
string str;
int len;
const int INF=0x3f3f3f3f;
int dp[1010];
bool judge(int i,int j){
    bool flag=1;
    int cnt(0);
    while(i<=j){
        if(str[i]==str[j]){
            i++;j--;
        }
        else {
            flag=0;
            break;
        }
    }
    if(flag) return 1;
    else return 0;
}
void ini(){
    for(int i=0;i<len;i++){
        int j;
        for(int j=0;j<=i;j++){
            if(judge(j,i))
            {
                if(j==0) dp[i]=1;
                else dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
    }
}
int main(){
	int T;
	int nc(1);
	scanf("%d",&T);
	getchar();
	memset(dp,INF,sizeof(dp));
	while(T--){
        cin>>str;
        len=str.length();
        //cout<<judge(0,len-1)<<endl;
        ini();
        printf("Case %d: %d\n",nc++,dp[len-1]);
        memset(dp,INF,sizeof(dp));
	}
	return 0;
}
