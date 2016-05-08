/*
水题
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int n,m,res;

int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

char w[maxn+10][maxn+10];

void dfs(int x,int y){
     w[x][y]='*';
     for(int i=0;i<8;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&w[nx][ny]=='@') dfs(nx,ny);
     }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
        res=0,memset(w,0,sizeof(w));
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        scanf(" %c",&w[i][j]);
                }
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        if(w[i][j]=='@'){
                                dfs(i,j);
                                res++;
                        }
                }
        }
        printf("%d\n",res);
    }
    return 0;
}
