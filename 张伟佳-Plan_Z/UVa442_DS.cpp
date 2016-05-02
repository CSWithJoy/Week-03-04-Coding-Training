// water
#include <bits/stdc++.h>
using namespace std;
struct Matrix {
	int m, n;
	Matrix ():m(-1), n(-1) {}
	Matrix (int m, int n):m(m), n(n) {}
};
Matrix mat[30], stk[100];
char expr[300];
int len, p;

int main() {
	int n, ans=0;
	Matrix cur;
	p=0;
	scanf("%d%*c", &n);
	for (int i=0;i<n;++i) {
		char ch;
		int a, b;
		scanf("%c %d %d%*c", &ch, &a, &b);
		mat[ch-'A']=Matrix(a, b);
	}
	while (scanf("%s", expr)!=EOF) {
		len=strlen(expr);
		bool flag=true;
		ans=0;
		p=0;
		for (int i=0;i<len;++i) {
			char ch=expr[i];
			if (ch>='A'&&ch<='Z') {
				stk[p++]=mat[ch-'A'];
			}else if (ch==')') {
				if (p>1) {
					if (stk[p-1].m!=stk[p-2].n) {
						flag=false;
						break;
					}
					cur=Matrix(stk[p-2].m, stk[p-1].n);
					ans+=stk[p-2].m*stk[p-2].n*stk[p-1].n;
					p-=2;
					stk[p++]=cur;
				}
			}
		}
		if (!flag) printf("error\n");
		else printf("%d\n", ans);
	}
	return 0;
}