// water
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int posl, posr;
void build(int pos) {
	int val;
    scanf("%d", &val);
    if (val<0) return;
    mp[pos]+=val;
    posl=min(posl, pos);
    posr=max(posr, pos);
    build(pos-1);
    build(pos+1);
}

int main() {
    int icase=1;
    for (;;) {
        mp.clear();
        posl=posr=0;
        build(0);
        if (posl-posr==0 &&mp[posl]==0) break;
		printf("Case %d:\n", icase++);
		for (int i=posl;i<=posr;++i) printf("%d%c", mp[i], i==posr?'\n':' ');
		printf("\n");
    }
	return 0;
}
