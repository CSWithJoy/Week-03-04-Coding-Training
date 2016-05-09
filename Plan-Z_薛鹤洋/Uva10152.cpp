/*
这道题 orz，刚开始想的不是最优解 wa了10发，思路是这样的：
首先，两堆最底下相等的部分，就是没动的部分，这部分不考虑，然后动了的第一个，肯定是被其他的被挤下来的。
它所对应的初始状态有一个高度，因为它是从这个高度到了现在这个高度，所以这两个高度中间所有的龟都肯定动了，
所以第二堆继续往上，如果有龟的起始高度高于前面的那个高度，更新，否则它就属于中间那部分肯定动了的。
举个例子 起始 1 2 3 4 5 结束 5 4 3 2 1 1起始高度是5 结束高度是1 那么中间的2 3 4 5肯定是都动了的
所以2看上去像被挤下来的，但它的起始高度小于1，结束高度却大于1，2肯定动了。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int t,n,maxx,flag;

char a[maxn+10];

int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        flag=0,maxx=1;
        map<int,string> m1;
        map<int,string> m2;
        scanf("%d",&n);
        getchar();
        for(int j=n;j>=1;j--){
                gets(a);
                m1[j]=string(a);
        }
        for(int j=n;j>=1;j--){
                gets(a);
                m2[j]=string(a);
        }
        for(int j=1;j<=n;j++){
                if(m1[j]==m2[maxx]) maxx++;
        }
        for(int j=maxx;j<=n;j++) cout<<m2[j]<<endl;
        printf("\n");
    }
    return 0;
}
