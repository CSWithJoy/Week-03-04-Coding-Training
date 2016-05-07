//在字母组成的图中查找一个单词的首字母的坐标，由于不分大小写，所以先利用函数大小写统一
//当查找到第一个字母时，按照八个方向DFS一遍，查找是否有该单词
#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
char Map[60][60];
int r,c;
int X,Y;
int dir[8][2]={{1,0},{1,-1},{1,1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
void DFS(char input[])
{
	int len=strlen(input);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			for(int t=0;t<8;t++)
			{
				char str[50];
				str[0]=Map[i][j];
				int xx=i+dir[t][0];
				int yy=j+dir[t][1];
				int q=1;
				while(xx>=0&&xx<r&&yy>=0&&yy<c)
				{
					str[q++]=Map[xx][yy];
					if(q==len) break;
					xx+=dir[t][0];
					yy+=dir[t][1];
				}
				str[q]='\0';
				if(strcmp(str,input)==0)
				{
					X=i+1;
					Y=j+1;
					return;
				}
			}
		}
	return;
}
int main()
{
	int T,n,t=0;
	cin>>T;
	while(T--)
	{
		if(t!=0) cout<<endl;
		t++;
		cin>>r>>c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				cin>>Map[i][j];
				Map[i][j]=toupper(Map[i][j]);//将字母全部转化为大写
			}
		cin>>n;
		while(n--)
		{
			char word[60];
			cin>>word;
			int len=strlen(word);
			for(int i=0;i<len;i++) word[i]=toupper(word[i]);
			DFS(word);
			cout<<X<<' '<<Y<<endl;
		}
	}
	return 0;
}
