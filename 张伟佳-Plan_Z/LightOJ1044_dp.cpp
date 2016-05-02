// dp[i]表示到第i位置的时候，最少的分割数
// 转移时候遍历j=0~i的情况并判断j~i的串是否回文串，是就转移。
// O(n^2)
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
char str[maxn];
int dp[maxn];

int main() {
  int T, icase=1, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", str);
    n=strlen(str);
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=1;i<=n;++i) {
      for (int j=1;j<=i;++j) {
        bool flag=true;
        for (int k=j;k<(i+j+1)>>1;++k) {
          if (str[k-1]!=str[i+j-k-1]) {
            flag=false;
            break;
          }
        }
        if (flag) {
          dp[i]=min(dp[i], dp[j-1]+1);
        }
      }
    }
    printf("Case %d: %d\n", icase++, dp[n]);
  }
  return 0;
}