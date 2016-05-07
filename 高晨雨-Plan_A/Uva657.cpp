//双重DFS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 55
int w,h,t;
char Map[MAX][MAX];
int num[1000];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void DFS1(int x,int y)
{
	Map[x][y]='*';
	int xx,yy;
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(xx>0&&xx<=h&&yy>0&&yy<=w)
		{
			if(Map[xx][yy]=='X') DFS1(xx,yy);
		}
	}
}
void DFS2(int x,int y)
{
	int xx,yy;
	Map[x][y]='.';
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(xx>0&&xx<=h&&yy>0&&yy<=w)
		{
			if(Map[xx][yy]=='X')
			{
				num[t]++;
				DFS1(xx,yy);
			}
			if(Map[xx][yy]=='*')
			{
				DFS2(xx,yy);
			}
		}
	}
}
int main()
{
	int n=0;
	while(scanf("%d%d",&w,&h)!=EOF)
	{
		if(w==0&&h==0) break;
		memset(Map,'.',sizeof(Map));
		memset(num,0,sizeof(num));
		t=0;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			    cin>>Map[i][j];
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			{
				if(Map[i][j]=='*')
				{
					DFS2(i,j);
					t++;
				}
			}
		sort(num,num+t);
		printf("Throw %d\n",++n);
		printf("%d",num[0]);
		if(t>1)
			for(int i=1;i<t;i++)
				printf(" %d",num[i]);
		printf("\n\n");
	}
	return 0;
}
