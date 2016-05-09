/*
根据题目中的先序，建立两个二叉树，然后计算黑色的值。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

typedef struct QuadNode{
   int color;
   struct QuadNode *Node[4];
}QuadNode,*Quadtrees;

int t,ans;

Quadtrees build_tree(){
    char a;
    scanf("%c",&a);
    if(a=='e') return NULL;
    Quadtrees root=(QuadNode*)malloc(sizeof(QuadNode));
    if(a=='p') {
        for(int i=0;i<4;i++) root->color=0,root->Node[i]=build_tree();
    }
    if(a=='f'){
        root->color=1;
        for(int i=0;i<4;i++) root->Node[i]=NULL;
    }
    return root;
}

void dfs(Quadtrees &T1,Quadtrees &T2,int depth){
        if(!T1&&!T2) return ;
        if(T1&&!T2){
                if(T1->color==1){
                       ans+=(1024>>(2*depth));
                      // printf("%d\n",ans);
                     // printf("1\n");
                       return ;
                } else {
                    for(int i=0;i<4;i++) dfs(T1->Node[i],T2,depth+1);
                    return ;
                }
        }
        if(T2&&!T1){
                if(T2->color==1){
                       ans+=(1024>>(2*depth));
                     //  printf("%d\n",ans);
                     //printf("2\n");
                       return ;
                } else {
                    for(int i=0;i<4;i++) dfs(T1,T2->Node[i],depth+1);
                    return ;
                }
        }
        if(T1->color||T2->color) {ans+=(1024>>(2*depth));/*printf("3\n");*/return ;}
        for(int i=0;i<4;i++) dfs(T1->Node[i],T2->Node[i],depth+1);
}

int main()
{
    scanf("%d",&t);
    getchar();
    for(int h=1;h<=t;h++){
        ans=0;
        Quadtrees T1=build_tree();getchar();
        Quadtrees T2=build_tree();getchar();
        dfs(T1,T2,0);
        printf("There are %d black pixels.\n",ans);
    }
    return 0;
}
