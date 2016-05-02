// 状压dp 做过好几道类似的了
#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
int hp[maxn], dp[65536][maxn];
char dmg[maxn][maxn];

int main() {
  int T, icase=1, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i=0;i<n;++i) scanf("%d", hp+i);
    for (int i=0;i<n;++i) scanf("%s", dmg+i);
    for (int i=0;i<n;++i) dp[1<<i][i]=hp[i];

    for (int i=1;i<n;++i) {
      for (int j=0;j<(1<<n);++j) {
        int cnt=0, tmp=j;
        while (tmp) {
          if (tmp&1) ++cnt;
          tmp>>=1;
        }
        if (cnt!=i) continue;
        for (int k=0;k<n;++k) {
          int cur=1<<k;
          if (cur&j) continue;
          for (int u=0;u<n;++u) { 
            if (j&(1<<u)) {
              for (int v=0;v<n;++v) {
                int cdmg=dmg[u][k]-'0';
                if (cdmg) dp[cur|j][k]=min(dp[cur|j][k], dp[j][v]+(hp[k]-1)/cdmg+1);
                else dp[cur|j][k]=min(dp[cur|j][k], dp[j][v]+hp[k]);
              }
            }
          }
        }
      }
    }
    int ans=0x3f3f3f3f;
    for (int i=0;i<n;++i) ans=min(ans, dp[(1<<n)-1][i]);
    printf("Case %d: %d\n", icase++, ans);
  }
  return 0;
}