#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char mp[100][100];
int dir[8][2]=//zheshi8gefangxiangdechuli
{{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,0},{1,1},{1,-1}};
int vis[100][100];
int n,m ,ans;
void dfs(int i,int j){
    vis[i][j]=1;
    for(int k=0;k<8;k++){
        int x=i+dir[k][0];
        int y=j+dir[k][1];
        if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&mp[x][y]=='@'){
            dfs(x,y);
        }
    }
    return ;
}
int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
            scanf("%s",&mp[i]);
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        if(!vis[i][j]&&mp[i][j]=='@'){
            ans++;
            dfs(i,j);
        }
        printf("%d\n",ans);
    }
    return 0;
}
