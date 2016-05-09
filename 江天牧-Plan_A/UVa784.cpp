//简单搜索
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a_room[81][81];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int x,int y)
{
    a_room[x][y] = '#';
    for(int i = 0; i< 4;i ++)
    {
        int n_x = x+dx[i];
        int n_y = y + dy[i];
        if(a_room[n_x][n_y] == ' ')
        {
            dfs(n_x,n_y);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    getchar();
    while(T--)
    {
        //memset(a_room,0,sizeof(a_room));
        int i = 0;
        int x_begin,y_begin;
        int find_begin = 0;
        while(gets(a_room[i++]))
        {
            if(a_room[i-1][0] == '_')
                break;
            int row_len = strlen(a_room[i-1]);
            if(!find_begin)
            {
                for(int j = 0; j < row_len;j++)
                {
                    if(a_room[i-1][j] == '*')
                    {
                        x_begin = i-1;
                        y_begin = j;
                        find_begin = 1;
                    }
                }
            }
        }
        dfs(x_begin,y_begin);
        int col_num = i;
        for(i = 0;i<col_num;i++)
        {
            int row_len = strlen(a_room[i]);
            for(int j = 0;j<row_len;j++)
            {
                printf("%c",a_room[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
