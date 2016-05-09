/*
后序遍历的最后一个节点是根节点，然后在中序遍历中找到这个根节点，左边的是左子树，右边的是右子树。
递归构造出一颗二叉树，然后dfs找出最短路径
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=10000;

using namespace std;

int n;

int in_order[maxn+10],post_order[maxn+10],lch[maxn+10],rch[maxn+10];

bool read_list(int* a){
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n=0;
    int x;
    while(ss>>x) a[n++]=x;
    return n>0;
}

int build_tree(int L1,int R1,int L2,int R2){
    if(L1>R1) return 0;
    int root=post_order[R2];
    int p=L1;
    while(in_order[p]!=root) p++;
    int cnt=p-L1;
    lch[root]=build_tree(L1,p-1,L2,L2+cnt-1);
    rch[root]=build_tree(p+1,R1,L2+cnt,R2-1);
    return root;
}

int best,best_sum;

void dfs(int u,int sum){
   sum+=u;
   if(!lch[u]&&!rch[u]) {
        if(sum<best_sum||(sum==best_sum&&u<best)) {best=u;best_sum=sum;}
   }
   if(lch[u]) dfs(lch[u],sum);
   if(rch[u]) dfs(rch[u],sum);
}

int main()
{
    while(read_list(in_order)){
        read_list(post_order);
        build_tree(0,n-1,0,n-1);
        best_sum=inf;
        dfs(post_order[n-1],0);
        printf("%d\n",best);
    }
    return 0;
}
