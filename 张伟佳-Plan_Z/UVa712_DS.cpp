// water
#include <bits/stdc++.h>
using namespace std;
char res[10];

int main() {
	int n, icase=1, t;
	while (scanf("%d%*c", &n)&& n) {
		for (int i=0;i<n;++i) scanf("%*c%*d%*c");
		scanf("%s", res);
		scanf("%d%*c", &t);
		printf("S-Tree #%d:\n", icase++);
		while (t--) {
            char ch;
            int l=0, r=1<<n;
            while (scanf("%c", &ch)&&ch!='\n') {
                if (ch=='0') {
                    r=l+r>>1;
                }else {
					l=l+r>>1;
                }
            }
            printf("%c", res[l]);
		}
		printf("\n\n");
	}

	return 0;
}
