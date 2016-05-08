/*
要先把/和\ 转化，把/转化成 0 0 1 \转化为 1 0 0   1代表围墙，0代表路。
                           0 1 0         0 1 0
                           1 0 0         0 0 1
如果是围墙围起来的通路，不会走出边界，走出边界说明没有围成圈。

*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=500;

using namespace std;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int w,h,ans,res,mark,sum_cir,icase,a[maxn+10][maxn+10],flag[maxn+10][maxn+10];

char ch;

void init(){
    ans=0;
    res=0;
    mark=0;
    sum_cir=0;
    memset(a,0,sizeof(a));
    memset(flag,0,sizeof(flag));
    printf("Maze #%d:\n",++icase);
}

void dfs(int x,int y){
     flag[x][y]=1,res++;
     for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(nx>=0&&nx<3*h&&ny>=0&&ny<3*w){
                if(!flag[nx][ny]&&a[nx][ny]==0)
                dfs(nx,ny);
        }
        else mark=1;
     }
}

int main()
{
    while(scanf("%d%d",&w,&h)!=EOF&&w&&h){
        init();
        for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                scanf(" %c",&ch);
                if(ch=='\\'){
                a[i*3][j*3]=1,a[i*3+1][j*3+1]=1,a[i*3+2][j*3+2]=1;
                } else if(ch=='/'){
                a[i*3][j*3+2]=1,a[i*3+1][j*3+1]=1,a[i*3+2][j*3]=1;
                }
        }
       }
       /*for(int i=0;i<3*h;i++){
        for(int j=0;j<3*w;j++){
                printf("%d ",a[i][j]);
        }
        printf("\n");
       }*/
       for(int i=0;i<3*h;i++){
        for(int j=0;j<3*w;j++){
                if(a[i][j]==0&&!flag[i][j]){
                        res=0,mark=0;
                        dfs(i,j);
                        if(!mark){
                        sum_cir++;
                        ans=max(ans,res);
                        }
                }
        }
       }
       //printf("%d %d %d\n",sum_cir,ans/3,res);
       if(!sum_cir) printf("There are no cycles.\n");
       else printf("%d Cycles; the longest has length %d.\n",sum_cir,ans/3);
       printf("\n");
    }
    return 0;
}
