//模拟双向约瑟夫环
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int N;
int people[25];//从0开始到N-1模拟N个人的环
int Jm(int now,int m)//m从N-1位置开始逆时针每次数m个
{
	int cnt=0;
	for(;cnt!=m;now--)
	{
		if(now==-1) now=N-1;
		if(people[now]) cnt++;
	}
	return now+1;
}
int Jk(int now,int k)//k从0开始顺时针
{
	int cnt=0;
	for(;cnt!=k;now++)
	{
		if(now==N) now=0;
		if(people[now]) cnt++;
	}
	return now-1;
}
int main()
{
	int k,m;
	while(scanf("%d%d%d",&N,&k,&m)!=EOF)
	{
		if(N==0&&m==0&&k==0) break;
		memset(people,1,sizeof(people));
		int t=N,flag=0,kk=0,mm=N-1;
		while(t)
		{
			kk=Jk(kk,k);
			mm=Jm(mm,m);
			t--;
			if(flag) printf(",");
			people[kk]=0;
			people[mm]=0;
			flag=1;
			if(kk==mm) printf("%3d",kk+1);
			else{
				printf("%3d%3d",kk+1,mm+1);
				t--;
			}
		}
		printf("\n");
	}
	return 0;
}
