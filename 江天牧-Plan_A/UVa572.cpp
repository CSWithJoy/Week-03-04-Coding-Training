//求联通块的块数，简单搜索
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int n,m;
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};
int vis[100][100];
char oil[100][100];
void dfs(int x,int y)
{
    vis[x][y] = 1;
    for(int i = 0; i < 8;i++)
    {
        int x_n = x + dx[i];
        int y_n = y + dy[i];
        if(x_n<n&&y_n<m&&x_n>=0&&y_n>=0&&!vis[x_n][y_n]&&oil[x_n][y_n] == '@')
        {

            dfs(x_n,y_n);
        }
    }
}
int main()
{

    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++)
        {
            scanf("%s",oil[i]);
        }
        int sum = 0;
        for(int i = 0; i< n;i++)
        {
            for(int j = 0;j <m;j++)
            {
                if(!vis[i][j]&&oil[i][j] == '@')
                {
                    dfs(i,j);
                    sum ++;
                }
            }
        }
        cout << sum <<endl;
    }
    return 0;
}
