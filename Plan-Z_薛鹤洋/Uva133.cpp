/*
这题用list模拟太过复杂，直接用数组模拟比较简单。
紫薯上总结了一个公式：p=（p+d+n-1）%n+1;
我只记住了，实际意义还没有理解。。。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int n,k,m,cnt,off1,off2,a[maxn+10],flag[maxn+10];

int mov(int now,int off,int step){
       if(off==1){
        if(!flag[now]) step--;
        for(int i=1;i<=step;i++){
               do{
                now=now%n+1;
               } while(flag[now]);
        }
       } else {
          if(!flag[now]) step--;
          for(int i=1;i<=step;i++){
                do{
                    now-=1;
                    if(now==0) now=n;
                } while(flag[now]);
        }
       }
       return now;
}

int main()
{
    while(scanf("%d%d%d",&n,&k,&m)!=EOF&&(n&&k&&m)){
        memset(flag,0,sizeof(flag)),cnt=0;
        for(int i=1;i<=n;i++) a[i]=i;
        off1=1,off2=n;
        while(cnt!=n){
           cnt++;
           off1=mov(off1,1,k),off2=mov(off2,0,m);
           printf("%3d",off1);
           if(off1!=off2) {
                printf("%3d",off2);
                cnt++;
           }
           flag[off1]=flag[off2]=1;
           if(cnt!=n) printf(",");
        }
        printf("\n");
    }

    return 0;
}
