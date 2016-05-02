// omoshiroi
// 先找出每个骰子所在区域，搜索完，然后再在骰子区域中dfs骰子中点的区域
// 否则一起搜索时出现点将骰子的区域分为两块地情况无法处理
/*
..............................
........***........******.....
.......**X****.....*X**X*.....
......X******......******.....
.....*X**X**.......*X**X*.....
........***........******.....
像这种里面左边的骰子
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=60;
char mp[maxn][maxn], mask[maxn][maxn];
int w, h, ans[600], sz=0;
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
struct P {
  int x, y;
  P() {}
  P(int x, int y):x(x), y(y) {}
};

void show() {
  for (int i=0;i<h;++i) {
    for (int j=0;j<w;++j) {
      printf("%c", mp[i][j]);
    }
    printf("\n");
  }
}

void dfs2(int i, int j) {
  mp[i][j]='.';
  for (int k=0;k<4;++k) {
    int nx=j+dx[k], ny=i+dy[k];
    if (nx<0||nx>=w||ny<0||ny>=h) continue;
    if (mp[ny][nx]=='x') {
      dfs2(ny, nx);
    }
  }
}

void dfs1(int i, int j) {
  if (mp[i][j]=='*') mp[i][j]='.';
  else mp[i][j]='x';
  mask[i][j]=sz;
  for (int k=0;k<4;++k) {
    int nx=j+dx[k], ny=i+dy[k];
    if (nx<0||nx>=w||ny<0||ny>=h) continue;
    if (mp[ny][nx]=='*'||mp[ny][nx]=='X') {
      dfs1(ny, nx);
    }
  }
}

int main() {
  int icase=1;
  while (scanf("%d%d", &w, &h)&&w&&h) {
    for (int i=0;i<h;++i) scanf("%s", mp[i]);
    sz=0;
    memset(ans, 0, sizeof(ans));
    memset(mask, 0xff, sizeof(mask));
    for (int i=0;i<h;++i) {
      for (int j=0;j<w;++j) {
        if (mp[i][j]=='*') {
          dfs1(i, j);
          ++sz;
        }
      }
    }
    for (int i=0;i<h;++i) {
      for (int j=0;j<w;++j) {
        if (mp[i][j]=='x') {
          ans[mask[i][j]]++;
          dfs2(i, j);
        }
      }
    }
    sort(ans, ans+sz);
    printf("Throw %d\n", icase++);
    for (int i=0;i<sz;++i) printf("%d%c", ans[i], i==(sz-1)?'\n':' ');
    printf("\n");
  }
  return 0;
}