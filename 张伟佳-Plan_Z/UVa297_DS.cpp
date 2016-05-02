// 模仿二叉树用数组存四叉树，递归计算结果的时候条件要小心处理
#include <bits/stdc++.h>
using namespace std;
const int maxn=1024;
int qt1[maxn<<4], qt2[maxn<<4];

void build(int p, int *qt) {
    char ch;
    scanf("%c", &ch);
    if (ch=='p') {
        qt[p]=-1;
        for (int i=0;i<4;++i) build(p<<2|i, qt);
    }else if (ch=='e') qt[p]=0;
    else qt[p]=1;
}

int merge(int p, int dep) {
    int ret=0;
    if (qt1[p]==1||qt2[p]==1) {
        ret=1<<((5-dep)<<1);
        return ret;
    }else if (qt1[p]==-1||qt2[p]==-1) {
        for (int i=0;i<4;++i) ret+=merge(p<<2|i, dep+1);
        return ret;
    }else return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
		memset(qt1, 0, sizeof(qt1));
		memset(qt2, 0, sizeof(qt2));
		scanf("%*c");
		build(1, qt1);
		scanf("%*c");
		build(1, qt2);
		printf("There are %d black pixels.\n", merge(1, 0));
    }
	return 0;
}
