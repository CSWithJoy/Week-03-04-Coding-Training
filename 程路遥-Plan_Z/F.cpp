#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

string str1,str2;
int ans;
int tree[6][1030];
stack<int>s;
void build(){
    int depth=1,heng=0;
    int cnt;
    while(!s.empty()) s.pop();
    s.push(0);
    for(int i=1;i<str1.length();i++){
        if(str1[i]=='p'){
            cnt++;
            depth++;
            heng*=4;
            s.push(cnt);
            cnt=0;
            continue;
        }
        if(str1[i]=='f'){
            tree[depth][heng]=1;
            heng++;
            cout<<"d"<<endl;
        }
        cnt++;
        heng++;
        if(cnt==4){
            depth--;
            cnt=s.top();
            s.pop();
        }
    }
    depth=1;heng=0;
    while(!s.empty()) s.pop();
    for(int i=1;i<str2.length();i++){
        if(str2[i]=='p'){
            depth++;
            heng*=4;
            s.push(cnt);
            cnt=0;
            continue;
        }
        if(str2[i]=='f'){
            tree[depth][heng]=1;
        }
        cnt++;
        if(cnt==4){
            depth--;
            cnt=s.top();
            s.pop();
        }
    }
}
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
        memset(tree,0,sizeof(tree));
        cin>>str1;
        getchar();
        cin>>str2;
        cout<<str1<<endl<<str2<<endl;
        //tree[6][1030]
        build();
        ans=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<30;j++)
                cout<<tree[i][j];
            cout<<endl;
        }
        printf("There are %d black pixels.",ans);
	}
	return 0;
}
