//概率dp和那道骰子很像，就是没想到/cnt-1 ，查了题解才明白，还是见得太少，弱爆了TAT
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double dp[100010];
	int t, Case = 1;
	int n;

	memset( dp, 0, sizeof( dp ) );

	dp[1] = 0;
	for( int i = 2; i <= 100000; i++ )
	{
		double sum = 0;
		int cnt = 0;
		for( int j = 1; j * j <= i; j++ )
		{
			if( i % j == 0 )
			{
				sum += dp[j];
				cnt++;
				if( j != i / j )
				{
					sum += dp[i/j];
					cnt++;
				}
			}
		}
		dp[i] = ( sum + cnt ) / ( cnt - 1 );
	}

	cin >> t;
	while( t-- )
	{
		cin >> n;
		printf( "Case %d: %.10lf\n", Case++, dp[n] );
	}
	return 0;
}
