// water
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
char mp[maxn][maxn];
int n, m, dx[8]={0,1,1,1,0,-1,-1,-1}, dy[8]={-1,-1,0,1,1,1,0,-1};
struct P {
  int x, y;
  P() {}
  P(int x, int y):x(x), y(y) {};
};

void bfs(int i, int j) {
  queue<P> que;
  P cur;
  cur=P(j, i);
  que.push(cur);
  mp[i][j]='@';
  while (que.size()) {
    cur=que.front();
    que.pop();
    int cx=cur.x, cy=cur.y, nx, ny;
    for (int k=0;k<8;++k) {
      nx=cx+dx[k];
      ny=cy+dy[k];
      if (nx<0||nx>=n||ny<0||ny>=m||mp[ny][nx]=='*') continue;
      mp[ny][nx]='*';
      que.push(P(nx, ny));
    }
  }
}

int main() {
  int ans;
  while (scanf("%d%d%*c", &m, &n)&&m) {
    for (int i=0;i<m;++i) scanf("%s", mp[i]);
    ans=0;
    for (int i=0;i<m;++i) {
      for (int j=0;j<n;++j) {
        if (mp[i][j]=='@') {
          ++ans;
          bfs(i, j);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}