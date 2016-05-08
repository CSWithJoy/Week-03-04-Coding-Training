/*
题意:先找出有多少联通的'X*'区域，在这些区域中有多少联通的'X'
wa点：本来有很多*是不四联通的，但他们属于一个区域。
比如：. . . . .
      . . * * .
      . * X X *
      . . * * .
      . . . . .
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int maxn=100;

int w,h,die,icase,cnt[maxn*10+10];

char a[maxn+10][maxn+10];

int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

void dfs_dot(int x,int y){
  a[x][y]='*';
  for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(nx<=h&&ny<=w&&nx>=1&&ny>=1&&a[nx][ny]=='X')
        dfs_dot(nx,ny);
    }
}

void dfs_die(int x,int y){
   a[x][y]='.';
   for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
       if(nx<=h&&ny<=w&&nx>=1&&ny>=1&&a[nx][ny]!='.'){
        if(a[nx][ny]=='X'){
            dfs_dot(nx,ny);
            cnt[die]++;
        }
        if(a[nx][ny]=='*')
            dfs_die(nx,ny);
        }
    }
}

void init(){
  die=0;
  memset(a,'.',sizeof(a));
  memset(cnt,0,sizeof(cnt));
}

int main()
{
     while(scanf("%d%d",&w,&h)!=EOF&&w&&h){
        init();
        for(int i=1;i<=h;i++){
                for(int j=1;j<=w;j++) scanf(" %c",&a[i][j]);
        }
        for(int i=1;i<=h;i++)
           for(int j=1;j<=w;j++){
                if(a[i][j]=='*'){
                        dfs_die(i,j);
                        die++;
                }
        }
        //printf("%d\n",die);
        sort(cnt,cnt+die);
        printf("Throw %d\n",++icase);
        for(int i=0;i<die;i++) {
                if(!i) printf("%d",cnt[i]);
                else printf(" %d",cnt[i]);
        }
        printf("\n\n");
     }
     return 0;
}
