#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
char a[50+5][50+5];
int cnt;
void DFS1(int x,int y)
{
    if(a[x][y]!='X')
        return ;
    else
        a[x][y]='.';
    DFS1(x-1,y);    //题目要求只需要考虑上下左右四个方向即可，而不是八个方向
    DFS1(x,y-1);
    DFS1(x,y+1);
    DFS1(x+1,y);
}
void DFS2(int x,int y)
{
    if(a[x][y]=='.')
        return ;
    if(a[x][y]=='X')
    {
        DFS1(x,y);
        cnt++;
    }
    a[x][y]='.';
    DFS2(x-1,y);
    DFS2(x,y-1);
    DFS2(x,y+1);
    DFS2(x+1,y);
}
int main()
{
    int w,h,nc(1),ct,ans[100];
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        if(w==0&&h==0) break;
        memset(a,'.',sizeof(a));
        for(int i=1; i<=h; i++)
        {
            getchar();
            for(int j=1; j<=w; j++)
                scanf("%c",&a[i][j]);
        }
        ct=0;
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
                if(a[i][j]=='*'||a[i][j]=='X')
                {
                    cnt=0;
                    DFS2(i,j);
                    ans[ct++]=cnt;
                }
        printf("Throw %d\n",nc++);
        sort(ans,ct+ans);
        for(int i=0; i<ct; i++)
            {
                if(i)
                    printf(" ");
                printf("%d",ans[i]);
            }
        printf("\n\n");
    }
    return 0;
}
