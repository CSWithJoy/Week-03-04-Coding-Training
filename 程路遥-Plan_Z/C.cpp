#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
string str;
stack<char> s;
int main(){
	int T;
	cin>>T;
	getchar();
	while(T--){
        getline(cin,str);
        int i=0;
        bool flag=1;
        if(str[0]=='\n') flag=0;
        else
        for(i=0;i<str.length()&&flag;i++){
            if(str[i]=='('){
                s.push(str[i]);
                continue;
            }
            if(str[i]=='['){
                s.push(str[i]);
                continue;
            }
            if(str[i]==')'){
                if(!s.empty()&&s.top()=='(') {
                    flag=1;
                    s.pop();
                }
                else
                    flag=0;
            }
            if(str[i]==']'){
                if(!s.empty()&&s.top()=='[') {
                    flag=1;
                    s.pop();
                }
                else
                    flag=0;
            }
        }
        if(flag&&s.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        while(!s.empty()) s.pop();//这个WA了5发。。。
	}
	return 0;
}
