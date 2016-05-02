// 预处理dp[i][j]，表示首位是j的i位二进制数里所有连续11的个数
// 然后读入n之后，进行求解。
/*
    1 
   10 
   11  
  100
  101
  110
  111
 1000
 1001
 1010
 1011
 1100
 1101
 1110
*/
// 以该组数据为例 输入14
/*
最高位是1，则将dp[4][0]加入结果，如此一来所有小于或等于3位的二进制数都被统计了。
下一位也是1，则将dp[3][0]加入结果，如此一来最高位为10的四位二进制数都被统计了。
再下一位也是1， dp[2][0]加入结果，统计了1101和1100最低两位的结果。注意到1101和1100的最高两位无法被统计。
我们在依次访问的时候记录高位连续出现1的数量，然后把它累加至结果中就可以了。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[35][2], ans;
int n;

void init() {
  memset(dp, 0, sizeof(dp));
  for (int i=2;i<=32;++i) {
    dp[i][0]=dp[i-1][0]+dp[i-1][1];
    dp[i][1]=dp[i][0]+(1<<(i-2));
  }
}

int main() {
  int T, icase=1;
  init();
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    ans=0;
    ll cnt=0;
    for (int i=31;i>=0;--i) {
      if (n&(1<<i)) {
        ans+=dp[i+1][0]+cnt*(1<<i);
        if (i<=30 && (1<<(i+1))&n) ++cnt;
      }
    }
    ans+=cnt;
    printf("Case %d: %lld\n", icase++, ans);
  }
  return 0;
}