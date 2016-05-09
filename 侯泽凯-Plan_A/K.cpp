//少了一个空行。。。wa两发
#include<bits/stdc++.h>
using namespace std;

char maze[50][100];
int ax[4]={0,0,1,-1};
int ay[4]={1,-1,0,0};
int maxc,r;

void dfs(int x,int y)
{
	maze[x][y]='#';
	for(int i=0;i<4;i++)
	{
		int xx=x+ax[i];
		int yy=y+ay[i];
		if(maze[xx][yy]==' ')
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	int t,sx,sy;
	cin>>t;
	getchar();
	while(t--)
	{
		memset(maze,0,sizeof(maze));
		char temp;

		r=0;
		while(1)
		{
			maxc=-1;
			int c=0;
			while((temp=getchar())!='\n')
			{
				if(temp=='*')
				{
					sx=r;
					sy=c;
				}
				maze[r][c++]=temp;
			}
			maxc=max(maxc,c);
			if(maze[r][1]=='_')break;
			r++;
		}
		if(sx<r)
			dfs(sx,sy);
		for(int i=0;i<=r;i++)
		{
			puts(maze[i]);
		}
	}
	return 0;
}
