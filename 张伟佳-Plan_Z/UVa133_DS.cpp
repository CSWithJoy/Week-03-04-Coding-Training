// water
#include <bits/stdc++.h>
using namespace std;
int a[30];

int main() {
	int n, k, m, num;
	int cnt1, cnt2;
	int p1, p2;
	while (scanf("%d%d%d", &n, &k, &m) && n) {
		for (int i=0;i<n;++i) a[i]=i+1;
		p1=0;
		p2=n-1;
		num=n;
		while (a[p1]<0) p1=(p1+1)%n;
		while (a[p2]<0) p2=(p2-1+n)%n;
		while (num>0) {
			cnt1=k-1;
			cnt2=m-1;
			while (cnt1) {
				if (a[p1]>0) {
					--cnt1;
				}
				p1=(p1+1)%n;
			}
			while (cnt2) {
				if (a[p2]>0) {
					--cnt2;
				}
				p2=(p2-1+n)%n;
			}
			while (a[p1]<0) p1=(p1+1)%n;
			while (a[p2]<0) p2=(p2-1+n)%n;
			if (p1==p2) {
				printf("%3d", a[p1]);
				a[p1]=-1;
				num-=1;
			}else {
				printf("%3d%3d", a[p1], a[p2]);
				a[p1]=a[p2]=-1;
				num-=2;
			}
			if (num) printf(",");
		}
		printf("\n");
	}
	return 0;
}