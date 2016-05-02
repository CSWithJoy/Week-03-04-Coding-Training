// 推出数学期望的公式，得出D的数学期望和它的约数有关（除去D本身)
// 得到了一个等比*等差数列的形式求了和 错位相减 bla bla bla 得出
// E(D)=n*n/(n-1)/(n-1)+E(x1)/(n-1)+E(x2)/(n-1) ....
// 其中x1 x2 ...为D的约数（除D本身，包括1）。鉴于要重复查找所以采用了记忆化搜索
// 为了快速查找约数先预处理了一张素数表，然后跑质因数分解，然后组合，暴力会TLE
// omoshiroi.......
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
double ex[maxn];
bool sieve[maxn];
int prime[maxn/10], sz=0;

int fast_pow(int x, int y) {
  int base=x, res=1;
  while (y) {
    if (y&1) res*=base;
    base*=base;
    y>>=1;
  }
  return res;
}

double dfs(int n) {
  if (ex[n]>=0.0) return ex[n];
  int cnt=1, tmp=n, fac[30][2], facn=0;
  ex[n]=0.0;
  for (int i=0;tmp>1;++i) {
    if (tmp%prime[i]==0) {
      fac[facn][1]=0;
      fac[facn][0]=prime[i];
      while (tmp%prime[i]==0) {
        ++fac[facn][1];
        tmp/=prime[i];
      }
      cnt*=fac[facn][1]+1;
      facn++;
    }
  }
  for (int i=0;i<cnt-1;++i) {
    int t=i, cur=1;
    for (int j=0;t>0&&j<facn;++j) {
      cur*=fast_pow(fac[j][0], t%(fac[j][1]+1));
      t/=(fac[j][1]+1);
    }
    ex[n]+=(double)cnt/(double)((cnt-1)*(cnt-1))+dfs(cur)/(double(cnt-1));
  }
  return ex[n];
}

void init() {
  for (int i=0;i<maxn;++i) ex[i]=-1.0;
  ex[1]=0.0;
  memset(sieve, true, sizeof(sieve));
  for (int i=2;i<maxn;++i) {
    if (sieve[i]) prime[sz++]=i;
    for (int j=0;j<sz&&prime[j]*i<maxn;++j) {
      sieve[prime[j]*i]=false;
      if (!i%prime[j]) break;
    }
  }
}

int main() {
  int T, icase=1, n;
  scanf("%d", &T);
  init();
  while (T--) {
    scanf("%d", &n);
    printf("Case %d: %.10f\n", icase++, dfs(n));
  }
  return 0;
}