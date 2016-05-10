//根据中序排列和后序排列求从根到叶的最小路径
#include <iostream>
#include<cstdio>
const int MAXN = 10009;
const int INF = 0x3f3f3f3f;
using namespace std;
int in_order[MAXN],post_order[MAXN],L_ch[MAXN],R_ch[MAXN];
int read_list(int *a)
{
    char c = ' ';
    int i = 0;
    int flag;
    while(1)
    {
        flag = scanf("%d",&a[i++]);
        if(flag == -1)
        {
            i = 0;
            break;
        }


        c = getchar();
        if(c != ' ')
            break;
    }
    return i;
}
int n;
int path_min;
int leaf_min;
void dfs(int L1,int R1, int L2, int R2, int sum)
{
    if(L1 > R1)
        return;
    sum += post_order[R2];
    if(L1 == R1)
    {
        if(sum < path_min || (sum == path_min&&post_order[R2] < leaf_min ))
        {
            path_min = sum;
            leaf_min = post_order[R2];
        }
        return;
    }
    int p = L1;
    while(in_order[p] != post_order[R2])
    {
        p++;
    }
    //cout << p<<endl;
    int d_ = p - L1;
    dfs(L1,p-1,L2,L2 + d_ -1,sum);
    dfs(p+1,R1,L2 + d_,R2-1,sum);
}
int main()
{

    freopen("sample.txt","r",stdin);

    while(read_list(in_order)>=1)
    {
        n = read_list(post_order);
/*        for(int i = 0;i<n;i++)
        {
            cout<<in_order[i]<<endl;
        }
        for(int i = 0;i<n;i++)
        {
            cout<<post_order[i]<<endl;
        }*/
        path_min = INF;
        leaf_min = INF;
        dfs(0,n-1,0,n-1,0);
        cout << leaf_min<<endl;
    }
    return 0;
}
