//模拟约瑟夫环
#include<bits/stdc++.h>
using namespace std;

int d[25];
int n;

int in(int cur,int innum)
{
	int i=0;

	for( ;i!=innum;cur++)
	{
		/*cout<<"ok"<<endl;
		cout<<i<<" "<<innum<<endl;*/
		if(cur>n)
		{
			cur=1;
		}
		if(d[cur]==0)
		{
			i++;
		}
	}
	return --cur;
}

int off(int cur,int offnum)
{
	int i=0;
	for( ;i!=offnum;cur--)
	{
		if(cur<1)
		{
			cur=n;
		}
		if(d[cur]==0)
		{
			i++;
		}
	}
	return ++cur;
}

int main()
{
	int inorder,offorder;
	while(cin>>n>>inorder>>offorder)
	{
		if(n==0&&inorder==0&&offorder==0)
		{
			break;
		}
		memset(d,0,sizeof(d));
		//************注：只可赋值0*********//
		//写成memset（d，0，n）会TLE

		int cnt=n;
		int i=1,j=n;

		while(cnt>0)
		{

			i=in(i,inorder);

			j=off(j,offorder);

			if(i==j)
			{
				printf("%3d",i);
				d[i]=1;
				cnt--;
			}
			else
			{
				printf("%3d%3d",i,j);
				d[i]=d[j]=1;
				cnt-=2;
			}
			if(cnt!=0)
			{
				printf(",");
			}
			else
			{
				printf("\n");
			}
		}
	}
	return 0;
}


//运用公式求解
#include <stdio.h>

#define MAXN 25
int n,k,m;
int a[MAXN];

int go(int p, int order, int L)
{
     while (L--)//查找次数
	{
		do
		{
			p = (p+n+order)%n;
		} while(a[p] == 0);
	}
    return p;
}

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
	{
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
		}

        int left = n;//剩下的
        int pA = n-1, pB = 0;
        int pANext,pBNext;

        while (left)
        {
            pA = go(pA, 1, k);//1表示逆时针，因为它是逆时针标号
            pB = go(pB, -1, m);//-1表示顺时针
            printf("%3d", pA + 1);
            left--;
            if (pA != pB)
            {
            	printf("%3d", pB + 1);
            	left--;
			}
            a[pA] = a[pB] = 0;
            if (left) printf(",");
        }
        printf("\n");
    }
    return 0;
}
