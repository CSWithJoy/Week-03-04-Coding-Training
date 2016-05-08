#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=50;
int a[MAXN];
int main(){
    int n;
    int m,k;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
        if(n==0&&k==0&&m==0) break;
        for(int i=1;i<=n;i++)
            a[i]=i;
        int sizes=n;
        int pos1=n,pos2=1;
        while(sizes>0){
            for(int i=0;i<k;i++){
                do{
                    pos1=(pos1+1+n-1)%n+1;
                }while(a[pos1]==0);
            }
            for(int i=0;i<m;i++){
                do{
                    pos2=(pos2-1+n-1)%n+1;
                }while(a[pos2]==0);
            }
            a[pos2]=0;
            a[pos1]=0;
            printf("%3d",pos1);
            sizes--;
            if(pos1!=pos2){
                printf("%3d",pos2);
                sizes--;
            }
            if(sizes) cout<<',';
        }
        cout<<endl;
    }
    //cout<<endl;
	return 0;
}
