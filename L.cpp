/*
6 4
\//\\/
\///\/
//\\/\
\/\///
3 3
///
\//
\\\
0 0
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int m,n;
char mp[100][100];
int maze[200][200];
int sum;
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={-1,0,1,-1,0,1,1,-1};
bool judge(int x,int y){

}
void dfs(int x,int y,int step){
    if(maze[x][y]=2){
        sum=max{step,sum};
        return ;
    }
    else {
        maze[x][y]=2;
    }
    int k=0;
    int xx,yy;
    if(maze[x+1][y])
}
int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m==0&&n==0) break;
        getchar();
        int i,j;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='\\'){
                    maze[2*i][2*j]=0;
                    maze[2*i+1][2*j+1]=1;
                }
                else if(mp[i][j]=='/'){
                    maze[2*i+1][2*j]=0;
                    maze[2*i][2*j+1]=0;
                }
            }
            getchar();
        }
        for(i=0;i<2*n;i++){
            for(j=0;j<2*m;j++)
                cout<<maze[i][j];
            cout<<endl;
        }
        int ans=0;
        for(i=0;i<2*n;i++){
            for(j=0;j<2*m;j++){
                if(maze[i][j]==0){
                    sum=0;
                    dfs(i,j,0);
                    ans=max(ans,sum);
                }
            }
        }
    }
	return 0;
}
