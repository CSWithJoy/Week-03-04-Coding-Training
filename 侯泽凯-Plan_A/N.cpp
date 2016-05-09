//最长回文串和字符串长度的差
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[105];
int dp[105][105];

int main()
{
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		memset(dp,0,sizeof(dp));

		scanf("%s",&s);

		int len=strlen(s);

		for(int i=0;i<len;i++)
		{
			dp[i][i]=1;
		}

		for( int i = len-1; i>=0; i-- )
		{
			for( int j = i; j < len; j++ )
			{
				dp[i][j] = max( dp[i][j], dp[i][j-1] );

				for( int k = i; k < j; k++ )
				{
					if( s[k] == s[j] )//判断距离
					{
						dp[i][j] = max( dp[i][j], dp[k+1][j-1] + 2 );
					}
				}
			}
		}

		printf("Case %d: %d\n",z,len-dp[0][len-1]);
	}
	return 0;
}
