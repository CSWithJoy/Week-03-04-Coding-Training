// 吐血 居然有这种变态题目。果断扩大3倍dfs
#include <bits/stdc++.h>
using namespace std;
const int maxn=300;
int mp[maxn][maxn];
int m, n, dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
struct P {
  int x, y;
  P() {}
  P(int x, int y):x(x), y(y) {}
};

bool dfs(int dep, int x, int y) {
  if (dep>5&&mp[y][x]==1) {
    return true;
  }
  if (mp[y][x]!=0) return false;
  mp[y][x]=dep;
  for (int k=0;k<4;++k) {
    int nx=x+dx[k], ny=y+dy[k];
    if (nx<0||ny<0||nx>=n||ny>=m) continue;
    if (dfs(dep+1, nx, ny)) {
      mp[y][x]=0;
      return true;
    }
  }
  mp[y][x]=0;
  return false;
}

void show() {
  for (int i=0;i<m;++i) {
    for (int j=0;j<n;++j) {
      if (mp[i][j]<0) printf(" # ");
      else if (mp[i][j]==0) printf("   ");
      else printf("%3d", mp[i][j]);
    }
    printf("\n");
  }
}

int bfs(int x, int y) {
  int ret=0;
  queue<P> que;
  P cur;
  que.push(P(x, y));
  mp[y][x]=++ret;
  while (!que.empty()) {
    cur=que.front();
    que.pop();
    for (int k=0;k<4;++k) {
      int nx=cur.x+dx[k], ny=cur.y+dy[k];
      if (nx<0||ny<0||nx>=n||ny>=m) continue;
      if (mp[ny][nx]==0) {
        mp[ny][nx]=++ret;
        que.push(P(nx, ny));
      }
    }
  }
  return ret;
}

int main() {
  int icase=1;
  while (scanf("%d%d", &n, &m)&&m) {
    memset(mp, 0, sizeof(mp));
    for (int i=0;i<m;++i) {
      scanf("%*c");
      for (int j=0;j<n;++j) {
        char ch;
        scanf("%c", &ch);
        if (ch=='/') {
          mp[i*3][j*3+2]=mp[i*3+1][j*3+1]=mp[i*3+2][j*3]=-1;
        }else {
          mp[i*3][j*3]=mp[i*3+1][j*3+1]=mp[i*3+2][j*3+2]=-1;
        }
      }
    }
    m=m*3;
    n=n*3;
    int ans=0, cnt=0;
    for (int i=0;i<m;++i) {
      for (int j=0;j<n;++j) {
        int tmp=0;
        if (dfs(1, j, i)) {
          ++ans;
          cnt=max(bfs(j, i), cnt);
        }
      }
    }
    printf("Maze #%d:\n", icase++);
    if (ans) printf("%d Cycles; the longest has length %d.\n", ans, cnt/3);
    else printf("There are no cycles.\n");
    printf("\n");
  }
  return 0;
}
