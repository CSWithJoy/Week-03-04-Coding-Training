/*
建树的过程中记录各个位置的值
注意：这个题的第二个样例是分两部分的。。看清楚。。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int icase,flag,inde,a[maxn*10],dat[maxn+10];

string line;

typedef struct BitNode{
    int data,pos;
    struct BitNode *lch,*rch;
}BitNode,*Bitree;

Bitree build_tree(int pos){
     int d=dat[inde++];
     //printf("%d\n",index);
     if(d==-1) return NULL;
     Bitree root=(BitNode*)malloc(sizeof(BitNode));
     root->data=d;
     a[pos]+=d;
     root->lch=build_tree(pos-1);
     root->rch=build_tree(pos+1);
     return root;
}

int read_list(){
    flag=0,inde=0,memset(dat,0,sizeof(dat)),memset(a,0,sizeof(a));
    if(!getline(cin,line)) return 0;
    stringstream ss(line);
    int n=0,x;
    while(ss>>x) dat[n++]=x;
    if(dat[0]==-1) return 0;
    return 1;
}

int main()
{
    while(read_list()){
        printf("Case %d:\n",++icase);
        build_tree(maxn);
        for(int i=0;i<=2*maxn;i++){
                if(a[i]&&!flag) {
                flag=1;
                printf("%d",a[i]);
                } else if(a[i]&&flag) printf(" %d",a[i]);
        }
        printf("\n\n");
    }
    return 0;
}
