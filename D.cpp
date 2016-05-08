#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
using namespace std;
struct MATRIX{
    int m;
    int n;
}ma[30],x,y;
int ans;
string str;
stack<MATRIX>s;
bool panding(MATRIX a,MATRIX b){
    if(a.n==b.m) return 1;
    return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        int du;
        char c;
        cin>>c;
        du=c-'A';
        cin>>ma[du].m>>ma[du].n;
	}
	while(cin>>str){
        ans=0;
        bool flag=1;
        int len=str.length();
        int i;
        for(i=0;i<len;i++){
            if(str[i]>='A'&&str[i]<='Z')
                s.push(ma[str[i]-'A']);
            else if(str[i]==')'){//因为必然是有一个‘）’，我会算一次，不然就是加进去，不需要考虑
                y=s.top();//这个地方注意左乘和右乘的问题。。。思索了很久。。。
                s.pop();
                //cout<<x.m<<" "<<x.n<<endl;
                x=s.top();
                s.pop();
                //cout<<y.m<<" "<<y.n<<endl;
                if(!panding(x,y))
                {
                    flag=0;
                    break;
                }
                ans+=x.m*x.n*y.n;
                MATRIX z;
                z.m=x.m;
                z.n=y.n;
                s.push(z);
            }
        }
        if(flag) cout<<ans<<endl;
        else cout<<"error"<<endl;
	}
	return 0;
}
