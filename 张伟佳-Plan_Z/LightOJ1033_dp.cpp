// LCS
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int dp[maxn][maxn];
char str[maxn];

int main() {
  int T, icase=1, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", str);
    n=strlen(str);
    memset(dp, 0, sizeof(dp));
    for (int i=0;i<n;++i) {
      for (int j=0;j<n;++j) {
        if (str[i]==str[n-j-1]) {
          dp[i+1][j+1]=dp[i][j]+1;
        }else {
          dp[i+1][j+1]=max(dp[i][j+1], dp[i+1][j]);
        }
      }
    }
    printf("Case %d: %d\n", icase++, n-dp[n][n]);
  }
  return 0;
}