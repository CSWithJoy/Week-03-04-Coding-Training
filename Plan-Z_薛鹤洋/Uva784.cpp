/*
水题
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,row,clo;

char a[maxn+10][maxn+10];

int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

void dfs(int x,int y){
     a[x][y]='#';
     for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(a[nx][ny]==' ') dfs(nx,ny);
     }
}

int main()
{
    scanf("%d",&t);
    getchar();
    while(t--){
        row=0,memset(a,0,sizeof(a));
        while(gets(a[row])&&a[row][0]!='_') row++;
        for(int i=0;i<row;i++)
                for(size_t j=0;j<strlen(a[i]);j++)
                       if(a[i][j]=='*') dfs(i,j);
        for(int i=0;i<=row;i++) puts(a[i]);
    }
    return 0;
}
