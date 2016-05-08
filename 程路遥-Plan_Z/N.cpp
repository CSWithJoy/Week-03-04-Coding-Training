#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
string str;
int dp[200][200];
int main(){
	int T,nc(1);
	scanf("%d",&T);
	while(T--){
        cin>>str;
        int len=str.length();
        //cout<<len<<endl;
        for(int i=0;i<len;i++)
            dp[i][i]=dp[i][i+1]=0;
        for(int i=len-1;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(str[i]==str[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
                }
            }
        }
        /*for(int i=0;i<len;i++){
            for(int j=0;j<len;j++)
                cout<<dp[i][j]<<endl;
        }*/
        printf("Case %d: %d\n",nc++,dp[0][len-1]);
	}
	return 0;
}
