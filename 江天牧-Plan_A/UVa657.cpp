#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int vis[51][51];
char a_ma[51][51];
int n_num;
int dx[] = {0,0,1,-1};
int  dy[] = {1,-1,0,0};
void dfs(int x,int y,int dian)
{
    vis[x][y] = 1;
    if(dian && a_ma[x][y] == 'X')
    {
        n_num++;
        dian = 0;
    }
    if(a_ma[x][y] == 'X')
    {
        dian = 0;
    }
    else
    {
        dian = 1;
    }
    for(int i = 0;i < 4;i ++)
    {
        int n_x = x +dx[i];
        int n_y = y + dy[i];
        if(n_x >=0&&n_y>=0&&n_x<n&&n_y<m&&!vis[n_x][n_y]&&a_ma[n_x][n_y]=='X')
        {
            dfs(n_x,n_y,dian);
        }
    }
    for(int i = 0;i < 4;i ++)
    {
        int n_x = x +dx[i];
        int n_y = y + dy[i];
        if(n_x >=0&&n_y>=0&&n_x<n&&n_y<m&&!vis[n_x][n_y]&&a_ma[n_x][n_y]=='*')
        {
            dfs(n_x,n_y,dian);
        }
    }
}
int main()
{
    freopen("std.txt","r",stdin);
    int time = 1;
    while(scanf("%d%d",&m,&n)&&n&&m)
    {
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < n;i ++)
        {
            scanf("%s",a_ma[i]);
        }
        int num[80];
        int po = 0;
        for(int i = 0;i< n;i++)
        {
            for(int j = 0; j< m;j++)
            {
                if((a_ma[i][j]=='X'||a_ma[i][j] == '*')&&!vis[i][j])
                {
                    n_num = 0;
                    dfs(i,j,1);
                    num[po++] = n_num;
                }
            }
        }
        sort(num,num+po);
        printf("Throw %d\n",time++);
        cout << num[0];
        for(int i = 1;i<po;i++)
        {
            printf(" %d",num[i]);
        }
        printf("\n\n");
    }
    return 0;
}
