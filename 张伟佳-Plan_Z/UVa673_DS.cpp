// water
// 坑 记得考虑空串
#include <bits/stdc++.h>
using namespace std;
char a[150], para[10]="([)]";
int stk[150], p;

int main() {
	int T;
	bool flag;
	scanf("%d%*c", &T);
	while (T--) {
		gets(a);
		int l=strlen(a);
		p=0;
		flag=true;
		for (int i=0;i<l;++i) {
			if (a[i]=='('||a[i]=='[') {
				stk[p++]=i;
			}else {
				if (p==0 || a[stk[p-1]]!=para[(int)(strchr(para, a[i])-para-2)]) {
					flag=false;
					break;
				}
				--p;
			}
		}
		if (p) flag=false;
		printf("%s\n", flag?"Yes":"No");
	}
	return 0;
}