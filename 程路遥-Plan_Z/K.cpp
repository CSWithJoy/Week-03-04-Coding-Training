#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char mp[100][100];
void dfs(int x,int y){
    mp[x][y] = '#';
    if(mp[x-1][y] == ' ')
        dfs(x-1,y);
    if(mp[x][y-1] == ' ')
        dfs(x,y-1);
    if(mp[x+1][y] == ' ')
        dfs(x+1,y);
    if(mp[x][y+1] == ' ')
        dfs(x,y+1);
}
int main(){
	int T,k(0);
	scanf("%d",&T);
	while(T--){
        k=0;
        memset(mp,0,sizeof(mp));
        while(1){
            gets(mp[k]);
            if(mp[k][0]=='_'&&mp[k][1]=='_')break;
            k++;
        }
        /*for(int i=0;i<k;i++){
            puts(mp[i]);
        }*/
        int i,j;
        bool flag=1;
        for(i=0;i<k&&flag;i++){
            for(j=0;j<strlen(mp[i])&&flag;j++){
                if(mp[i][j]=='*'){
                    mp[i][j]='#';
                    dfs(i,j);
                    flag=0;
                }
            }
        }
        for(i=0;i<k;i++){
            puts(mp[i]);
        }
	}
	return 0;
}
