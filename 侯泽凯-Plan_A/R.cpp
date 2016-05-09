//请教的高晨雨，又看了她的代码。。。orz
#include<bits/stdc++.h>
using namespace std;

#define inf 0x7fffffff

char p[1005];
int minlen[1005];

int jug(int i,int j)
{
	while(i<j)
	{
		if(p[i]!=p[j])
		{
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		scanf("%s",&p);
		int len=strlen(p);

		for(int i=0;i<len;i++)
		{
			minlen[i]=inf;
			for(int j=0;j<=i;j++)
			{
				if(jug(j,i)==1)
				{
					if(j==0)
					{
						minlen[i]=1;
					}
					else
					{
						minlen[i]=min(minlen[i],minlen[j-1]+1);
					}
				}
			}
		}
		printf("Case %d: %d\n",z,minlen[len-1]);
	}
	return 0;
}
