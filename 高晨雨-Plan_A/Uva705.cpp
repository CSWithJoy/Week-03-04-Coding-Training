//把‘\’转化成100，‘/’转化成001，然后0代表可走，1或者边界皆不能通过，DFS查找可行路径
//           010           010
//           001           101
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int num=0,sum,Max,pos,h,w,f;
#define M 400
int Map[M][M];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void DFS(int x,int y)
{
	int xx,yy;
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if((xx>=0)&&(x<h*3)&&(yy>=0)&&(yy<w*3))
		{
			if(Map[xx][yy]==0)
			{
				pos++;
				Map[xx][yy]=1;
				DFS(xx,yy);
			}
		}
		else f=0;
	}
}
int main()
{
	int i,j;
	char s[200];
	while(scanf("%d%d",&w,&h),w+h)
	{
		getchar();
		num++;
		sum=0;Max=0;
		memset(Map,0,sizeof(Map));
		for(i=0;i<h;i++)
		{
			gets(s);
			for(j=0;j<w;j++)
			{
				if(s[j]=='\\')
				{
					Map[3*i][3*j]=1;
					Map[3*i+1][3*j+1]=1;
					Map[3*i+2][3*j+2]=1;
				}
				else
				{
					Map[3*i+2][3*j]=1;
					Map[3*i+1][3*j+1]=1;
					Map[3*i][3*j+2]=1;
				}
			}
		}
		for(i=0;i<3*h;i++)
			for(j=0;j<3*w;j++)
			{
				if(Map[i][j]==0)
				{
					pos=1;f=1;Map[i][j]=1;
					DFS(i,j);
					if(f)
					{
						sum++;
						if(pos>Max) Max=pos;
					}
				}
			}
		if (sum==0) printf("Maze #%d:\nThere are no cycles.\n\n",num);
        else printf("Maze #%d:\n%d Cycles; the longest has length %d.\n\n",num,sum,Max/3);
	}
	return 0;
}

