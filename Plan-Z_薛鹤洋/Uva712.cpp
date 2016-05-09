/*
题目太长，根据样例猜的题意。给你一串操作符，0是往左走，1是往右走，最后一层的叶子有对应的值
输出根据这个操作符走到的叶子的值。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100000;

using namespace std;

int n,m,node,icase,num[maxn+10],in[maxn+10],markdown[maxn+10];

string c;

char a[maxn+10],b[maxn+10];

int main()
{
    while(scanf("%d",&n)!=EOF&&n){
        printf("S-Tree #%d:\n",++icase);
        memset(in,0,sizeof(in)),memset(num,0,sizeof(num)),memset(markdown,0,sizeof(markdown));
        getchar();
        getline(cin,c);
        stringstream ss(c);
        int y=0;
        char x;
        while(ss>>x) {
        if(x!='x')
        in[y++]=x-'1';
        }
       // for(int i=0;i<y;i++) printf("%d",index[i]);
        scanf("%s",a);
        for(size_t i=0;i<strlen(a);i++){
                num[(1<<n)+i]=a[i]-'0';
                //printf("%d %d",num[(n<<1)+i],(n<<1)+i);
        }
       // printf("\n");
        //for(int i=8;i<=15;i++) printf("%d",num[i]);
        //printf("\n");
        scanf("%d",&m);
        y=0;
        for(int i=1;i<=m;i++){
                node=1;
                scanf("%s",b);
                for(size_t j=0;j<strlen(b);j++){
                        if(b[in[j]]=='1') node=node*2+1;
                        else if(b[in[j]]=='0') node*=2;
                }
                //printf("%d\n",index[2]);
                markdown[y++]=num[node];
                //printf("%d %d",node,num[node]);
        }
       // printf("\n");
        for(int i=0;i<y;i++) printf("%d",markdown[i]);
        printf("\n\n");
    }
    return 0;
}
