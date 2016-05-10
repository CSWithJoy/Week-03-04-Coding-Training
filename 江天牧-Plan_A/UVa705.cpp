//很巧妙的题，斜的边可以转化成一个9*9的格子，最后要注意，步数要如何转换回来
#include <iostream>
#include<cstdio>
#include<cstring>

const int h_max = 100;

using namespace std;

int graph[3*h_max][3*h_max];
int n,m;
bool exist_circle;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int bu;
void dfs(int x, int y)
{
    graph[x][y] = 1;
    bu++;
    /*cout << x<<endl;
    cout<<y<<endl;
    cout<<endl;*/
    if(x==0||y==0||x==3*n-1||y == 3*m-1)
    {
        exist_circle = false;
    }
    for(int i = 0; i<4;i ++)
    {
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if(n_x < 0||n_y<0||n_x >=3*n||n_y>=3*m)
            continue;
        if(!graph[n_x][n_y])
        {
            dfs(n_x,n_y);
        }
    }
}
int main()
{
    int TIME = 1;
    while(scanf("%d%d",&m,&n)&&n)
    {
        getchar();
        char temp_c;
        memset(graph,0,sizeof(graph));
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<m;j++)
            {
                temp_c = getchar();
                if(temp_c == '\\')
                {
                    graph[3*i][3*j] = 1;
                    graph[3*i+1][3*j + 1] = 1;
                    graph[3*i + 2][3*j +2] = 1;

                }
                else if(temp_c == '/')
                {
                    graph[3*i][3*j + 2] = 1;
                    graph[3*i+1][3*j +1] = 1;
                    graph[3*i+2][3*j] = 1;
                }
            }
            getchar();
        }
        int sum_circle = 0;
        int max_circle  = 0;
        /*for(int i = 0;i<3*n;i++)
        {
            for(int j = 0;j<3*m;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i = 0;i<3*n;i++)
        {
            for(int j = 0; j <3*m;j++)
            {
                if(!graph[i][j])
                {
                    bu = 1;
                    exist_circle = true;
                    dfs(i,j);
                    if(exist_circle)
                    {
                        sum_circle++;
                        if(bu > max_circle)
                            max_circle = bu;
                    }
                }
            }
        }
        printf("Maze #%d:\n",TIME++);
        if(sum_circle == 0)
            printf("There are no cycles.\n\n");
        else
            printf("%d Cycles; the longest has length %d.\n\n",sum_circle,max_circle/3);
    }
    return 0;
}
