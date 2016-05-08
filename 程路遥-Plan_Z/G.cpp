#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n,mp[20];
string str,du;
int solve(){
    int k=1;
    for(int i=0;i<n;i++){
        if(du[mp[i]]=='0') k*=2;
        else k=k*2+1;
    }
    return str[k-(1<<n)]-'0';
}
int main(){
    int nc=1;
    while(cin>>n){
        if(!n) break;
        printf("S-Tree #d:\n",nc++);
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            mp[i]=s[1]-'1';
        }
        int m;
        cin>>str>>m;
        while(m--){
            cin>>du;
            cout<<solve();
        }
        cout<<endl<<endl;
    }
	return 0;
}
