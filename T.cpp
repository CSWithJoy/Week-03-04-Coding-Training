#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
int m,n;
const int MAXN=55;
char mp[MAXN][MAXN];
string str;
int ans1,ans2;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,-1,0,1,-1,0,1};
void lookfor(){
    int i,j;
    int k;
    char du=str[0];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(mp[i][j]==du){
                int xx,yy;
                int flag=1;
                for(k=0;k<8;k++){
                    xx=i;
                    yy=j;
                    for(int p=1;p<str.length();p++){
                        xx+=dx[k];
                        yy+=dy[k];
                        if(mp[xx][yy]==str[p]) flag=1;
                        else{
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1) {
                        ans1=i+1;
                        ans2=j+1;
                        return ;
                    }
                }
            }
        }
    }
}
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
        cin>>m>>n;
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin>>mp[i][j];
                if(mp[i][j]>='a'&&mp[i][j]<='z'){
                    mp[i][j]=toupper(mp[i][j]);
                }
            }
        }
        int nc;
        cin>>nc;
        while(nc--){
            cin>>str;
            for(int i=0;i<str.length();i++){
                if(islower(str[i]))
                    str[i]=toupper(str[i]);
            }
            ans1=ans2=0;
            lookfor();
            cout<<ans1<<" "<<ans2<<endl;
        }
        if(T)cout<<endl;
	}
	return 0;
}
