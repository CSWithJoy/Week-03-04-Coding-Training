//少了一个*3，调了3天
#include<bits/stdc++.h>
using namespace std;

int maze[250][250];
int ax[4]={0,0,1,-1};
int ay[4]={1,-1,0,0};

int flag,cmaxl,temp,jug;
int w,h;

void dfs(int x,int y)
{
	maze[x][y]=1;
	temp++;

	for(int i=0;i<4;i++)
	{
		int xx=x+ax[i];
		int yy=y+ay[i];
		if(xx>=0&&xx<h*3&&yy>=0&&yy<w*3)
		{
			if(maze[xx][yy]==0)
			{
				dfs(xx,yy);
			}
		}
		else if(xx<0||xx>=h*3||yy<0||yy>=w*3)
		{
			jug=0;
		}
	}
}

int main()
{

	int z=1;
	while(cin>>w>>h,(w+h))
	{
		cmaxl=-1;
		flag=0;
		memset(maze,0,sizeof(maze));

		char e;

		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin>>e;
				if(e=='/')
				{
					maze[i*3+2][j*3]=1;
					maze[i*3+1][j*3+1]=1;
					maze[i*3][j*3+2]=1;
				}
				else
				{
					maze[i*3][j*3]=1;
					maze[i*3+1][j*3+1]=1;
					maze[i*3+2][j*3+2]=1;
				}
			}
		}
		for(int i=0;i<h*3;i++)
		{
			for(int j=0;j<w*3;j++)
			{
				if(maze[i][j]==0)
				{
					temp=0;

					jug=1;

					dfs(i,j);

					if(jug==1)
					{
						flag++;
						//cout<<temp<<endl;
						cmaxl=max(cmaxl,temp);
					}
				}
			}
		}

		printf("Maze #%d:\n",z++);
		if(flag==0)
		{
			printf("There are no cycles.\n");
		}
		else
		{
			printf("%d Cycles; the longest has length %d.\n",flag,cmaxl/3);
		}
		cout<<endl;
	}
	return 0;
}
