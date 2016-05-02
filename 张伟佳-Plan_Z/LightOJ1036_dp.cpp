// 根据题意发现传送带必须是直通上方或者左方，中间断开是没有意义的，交叉也是不允许的。
// 可以设计状态dp[i][j]表示从1行1列到i行j列矩形区域的最优解，随后选择放左方向的传送带还是上方向的传送带就可以了。
#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int m, n;
int dp[maxn][maxn], u[maxn][maxn], r[maxn][maxn];

int main() {
  int T, icase=1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    for (int i=1;i<=m;++i) {
      for (int j=1;j<=n;++j) {
        scanf("%d", &u[i][j]);
        u[i][j]+=u[i][j-1];
      }
    }
    for (int i=1;i<=m;++i) {
      for (int j=1;j<=n;++j) {
        scanf("%d", &r[i][j]);
        r[i][j]+=r[i-1][j];
      }
    }
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=m;++i) {
      for (int j=1;j<=n;++j) {
        dp[i][j]=max(dp[i-1][j]+u[i][j], dp[i][j-1]+r[i][j]);
      }
    }
    printf("Case %d: %d\n", icase++, dp[m][n]);
  }
  return 0;
}
/*
Uranium
 0  0 10  9
 1  3 10  0
 4  2  1  3
 1  1 20  0
Radium
10  0  0  0
 1  1  1 30
 0  0  5  5
 5 10 10 10
*/