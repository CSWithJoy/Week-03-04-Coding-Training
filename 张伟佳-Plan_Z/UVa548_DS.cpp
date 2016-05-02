// water
// 后序最后一个永远是root
#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
int in[maxn], post[maxn], pos[maxn];
int anssum, ans;

void dfs(int la, int ra, int lb, int rb, int sum) {
  if (la==ra-1) {
    if (anssum>sum+in[la]) {
      ans=in[la];
      anssum=sum+in[la];
    }
    return;
  }
  int root=post[rb-1], rtpos=pos[root];
  if (rtpos>la) dfs(la, rtpos, lb, lb+rtpos-la, sum+in[rtpos]);
  if (rtpos<ra-1) dfs(rtpos+1, ra, lb+rtpos-la, rb-1, sum+in[rtpos]);
}

int main() {
  int sz=0, cur, tmp;
  char ch;
  for (;;) {
    sz=0;
    while ((tmp=scanf("%d", &cur))!=EOF) {
      scanf("%c", &ch);
      in[sz]=cur;
      pos[cur]=sz;
      ++sz;
      if (ch=='\n') break;
    }
    if (tmp==EOF) break;
    sz=0;
    while (scanf("%d%c", &cur, &ch)) {
      post[sz++]=cur;
      if (ch=='\n') break;
    }
    anssum=0x3f3f3f3f;
    dfs(0, sz, 0, sz, 0);
    printf("%d\n", ans);
  }
  return 0;
}
/*
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255

*/