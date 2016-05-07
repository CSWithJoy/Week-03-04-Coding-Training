//我只能说我太不仔细了。。。
#include<bits/stdc++.h>
using namespace std;

char game[55][55];
int dot[1005];
int ax[4]={0,0,1,-1};
int ay[4]={1,-1,0,0};

int w,h,t;
int cnt;


void dfs_in(int x,int y)
{
	int xx,yy;
	game[x][y]='*';//q1：为什么设为‘.’会wa？
	for(int i=0;i<4;i++)
	{
		xx=x+ax[i];
		yy=y+ay[i];
		if(xx>=0&&xx<h&&yy>=0&&yy<w)
		{
			if(game[xx][yy]=='X')
				dfs_in(xx,yy);
		}
	}
}

void dfs_out(int x,int y)
{
	int xx,yy;
	game[x][y]='.';
	for(int i=0;i<4;i++)
	{
		xx=x+ax[i];
		yy=y+ay[i];
		if(xx>=0&&xx<h&&yy>=0&&yy<w)
		{
			if(game[xx][yy]=='X')
			{
				cnt++;
				dfs_in(xx,yy);
			}
			if(game[xx][yy]=='*')
			{
				dfs_out(xx,yy);
			}
		}
	}
}

int main()
{
	int z=1;
	while(scanf("%d%d",&w,&h)!=EOF)
	{
		if(w==0&&h==0)break;
		t=0;

		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>game[i][j];//不需要初始化

		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(game[i][j]=='*')
				{
					cnt=0;
					dfs_out(i,j);
					dot[t++]=cnt;
				}
			}
		}

		sort(dot,dot+t);

		printf("Throw %d\n",z++);

			for(int i=0;i<t;i++)
			{
				printf("%d%c",dot[i],((i==t-1)?'\n':' '));
			}

		printf("\n");
	}
	return 0;
}
