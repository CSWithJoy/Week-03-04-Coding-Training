//四叉树的遍历
#include<bits/stdc++.h>
using namespace std;

string s;
int buf[32][32];//记录点的状态
int cnt,p;

void draw(int &p,int r,int c,int w)//r==row;c==colomn;w是图的宽度
{
	char ch=s[p++];
	if(ch=='p')//用p去遍历树不引用就会造成p在一条路径上转
	{
		draw(p,r,c+w/2,w/2);//利用w不断地缩小范围（即查询子树）
		draw(p,r,c,w/2);
		draw(p,r+w/2,c,w/2);
		draw(p,r+w/2,c+w/2,w/2);
	}
	else if(ch=='f')//把子区域全部涂黑
	{
		for(int i=r;i<r+w;i++)
			for(int j=c;j<c+w;j++)
		{
			if(buf[i][j]==0)
			{
				buf[i][j]=1;
				cnt++;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(buf,0,sizeof(buf));
		cnt=0;
		for(int i=0;i<2;i++)
		{
			cin>>s;
			int p=0;
			draw(p,0,0,32);
		}
		printf("There are %d black pixels.\n",cnt);
	}
	return 0;
}
