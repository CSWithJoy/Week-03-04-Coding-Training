//四叉树，类似线段树的解法，对一个数组染色即可
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char date[1500];
int color[1025];

int now;
void dfs(int L,int R)
{
    char now_c = date[now++];
    if(now_c == 'f')
    {
        for(int i = L;i<=R;i++)
        {
            color[i] = 1;
        }
    }
    if(now_c == 'p')
    {
        int mid = (L+R)>>1;
        int mid_l = (mid+L)>>1;
        int mid_r = (mid+R)>>1;
        dfs(L,mid_l);
        dfs(mid_l +1,mid);
        dfs(mid+1,mid_r);
        dfs(mid_r+1,R);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    //getchar();
    while(T--)
    {
        now = 0;
        scanf("%s",date);
        //printf("%s",date);
        memset(color,0,sizeof(color));
        dfs(1,1024);
        scanf("%s",date);
        now = 0;
        dfs(1,1024);
        int sum = 0;
        for(int i = 1; i <=1024;i++)
        {
            if(color[i])
            {
                sum++;
            }
        }
        printf("There are %d black pixels.\n",sum);
    }
    return 0;
}
