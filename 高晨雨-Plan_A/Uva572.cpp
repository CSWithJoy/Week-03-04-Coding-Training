//******DFS******water*******
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define Max 105
char Map[Max][Max];
int m,n;
int dir[8][2]={{0,1},{0,-1},{1,0},{1,-1},{1,1},{-1,0},{-1,1},{-1,-1}};
void DFS(int x,int y)
{
	Map[x][y]='*';
	int xx,yy;
	for(int i=0;i<8;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n)
		{
			if(Map[xx][yy]=='@')
				DFS(xx,yy);
		}
	}
}
int main()
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0) break;
		memset(Map,'*',sizeof(Map));
		for(int i=1;i<=m;i++)
		   for(int j=1;j<=n;j++)
			 cin>>Map[i][j];
		int sum=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(Map[i][j]=='@')
				{
					sum++;
					DFS(i,j);
				}
			}
			cout<<sum<<endl;
	}
}
