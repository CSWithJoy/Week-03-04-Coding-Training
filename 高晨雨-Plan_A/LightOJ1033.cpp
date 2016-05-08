//题目等价于求一个序列和它的逆序列的LCS的大小
//状态转移方程:X[i]==Y[j]时：f[i][j]=f[i][j]+1;
//             X[i]!=Y[j]时：f[i][j]=max(f[i][j+1],f[i+1][j]);
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char X[105],Y[105];
int f[105][105];
int len;
int DP()
{
	for(int i=0;i<=len;i++)
		for(int j=0;j<=len;j++)
		{
			if(X[i]==Y[j])
			{
				f[i+1][j+1]=f[i][j]+1;
			}
			else{
				f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
			}
		}
}
int main()
{
	int T,kase=1;
	cin>>T;
	getchar();
	while(T--)
	{
		memset(X,'\0',sizeof(X));
		memset(Y,'\0',sizeof(Y));
		memset(f,0,sizeof(f));
		gets(X);
		len=strlen(X)-1;
		for(int i=0;i<=len;i++)
			Y[i]=X[len-i];
		DP();
		printf("Case %d: %d\n",kase,(len+1-f[len+1][len+1]));
		kase++;
	}
	return 0;
}
