/*
A是 m*p矩阵 B是 p*n矩阵 则A*B结果为 m*n矩阵乘法次数为 m*p*n p!=p时 error
用栈来模拟
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int n,len,row,ans,flag,column;

char ch,expr[maxn+10];

struct Matrix{
   int a,b;
   Matrix(int a=0,int b=0):a(a),b(b) {}
}m[maxn+10];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf(" %c%d%d",&ch,&row,&column);
        m[ch-'A'].a=row,m[ch-'A'].b=column;
    }
    while(scanf("%s",expr)!=EOF){
        ans=0,flag=0;
        stack<Matrix> s;
        len=strlen(expr);
        for(int i=0;i<len;++i){
                if(expr[i]>='A'&&expr[i]<='Z') s.push(m[expr[i]-'A']);
                else if(expr[i]==')'){
                        Matrix m2=s.top();s.pop();
                        Matrix m1=s.top();s.pop();
                        if(m1.b!=m2.a){flag=1;printf("error\n");break;}
                        ans+=m1.a*m1.b*m2.b;
                        s.push(Matrix(m1.a,m2.b));
                }
        }
        if(!flag) printf("%d\n",ans);
    }
    return 0;
}
