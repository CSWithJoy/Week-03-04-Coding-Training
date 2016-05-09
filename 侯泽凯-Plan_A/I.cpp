//油田问题2333
#include<bits/stdc++.h>
using namespace std;

int cnt;
char oil[105][105];
int vis[105][105];
int ax[8]={0,0,1,-1,1,1,-1,-1};
int ay[8]={1,-1,0,0,1,-1,1,-1};

void dfs(int i,int j)
{
	vis[i][j]=1;
	int xx,yy;
	for(int k=0;k<8;k++)
	{
		xx=i+ax[k];
		yy=j+ay[k];
		if(oil[xx][yy]=='@'&&vis[xx][yy]==0)
		{
			dfs(xx,yy);
		}
	}
	return;
}
int main()
{
	int m,n;
	while(cin>>m>>n,(m+n))
	{
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			cin>>oil[i][j];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
		{
			if(oil[i][j]=='@'&&vis[i][j]==0)
			{
				dfs(i,j);
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
