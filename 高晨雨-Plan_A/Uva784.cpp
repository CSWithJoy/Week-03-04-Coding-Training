//DFS遍历能走的通的格子，并把格子都赋成‘#’
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char maze[100][100];
int dir[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1}};
void DFS(int x,int y)
{
	if(maze[x][y]=='X'||maze[x][y]=='#') return;
	maze[x][y]='#';
	int xx,yy;
	for(int i=0;i<8;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(xx>=0&&yy>=0)
		   DFS(xx,yy);
	}
}
int main()
{
	char ch;
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		memset(maze,'X',sizeof(maze));
		int i,j;
		for(i=0;;i++){
			for(j=0;;j++)
			{
				ch=getchar();
				if(ch=='\n')
				{
					maze[i][j]='\0';
					break;
				}
				maze[i][j]=ch;
			}
			if(maze[i][0]=='_') break;
		}
		for(int a=0;a<i;a++)
		{
			for(int k=0;k<strlen(maze[a]);k++)
			{
				if(maze[a][k]=='*')
					DFS(a,k);
			}
		}
		for(int k=0;k<=i;k++)
		{
			printf("%s\n",maze[k]);
		}
	}
	return 0;
}
