#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int m,n;
char mp[65][65];
int cnt;
int ans[1000];
void dfs1(int x,int y){
    if(mp[x][y]!='X') return;
    else
        mp[x][y]='.';
    dfs1(x-1,y);
    dfs1(x+1,y);
    dfs1(x,y+1);
    dfs1(x,y-1);
}
void dfs2(int x,int y){
    if(mp[x][y]=='.') return;
    if(mp[x][y]=='X'){
        dfs1(x,y);
        cnt++;
    }
    mp[x][y]='.';
    dfs2(x-1,y);
    dfs2(x+1,y);
    dfs2(x,y+1);
    dfs2(x,y-1);
}
int main(){
    int nc(0);
	while(scanf("%d%d",&n,&m)!=EOF){
        memset(ans,9,sizeof(ans));
        if(m==0&&n==0) break;
        memset(mp,'.',sizeof(mp));
        int i,j;
        getchar();
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>mp[i][j];
            }
        }
        /*for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout<<mp[i][j];
            }
            cout<<endl;
        }*/
        int k=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(mp[i][j]=='*'||mp[i][j]=='X'){
                    cnt=0;
                    dfs2(i,j);
                    ans[k++]=cnt;
                    //cout<<cnt<<endl;
                }
            }
        }
        sort(ans,ans+k);
        printf("Throw %d\n",++nc);
        for(int i=0; i<k; i++)
        {
            if(i)
                printf(" ");
            printf("%d",ans[i]);
        }
         printf("\n\n");
	}
	return 0;
}
