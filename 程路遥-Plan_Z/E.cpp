#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int in[10010],post[10010];
string str;
int trans(){
    int i=0,k=0;
    int du=0;
    int len=str.length();
    //cout<<len<<endl;
    for(i=0;i<len;i++){
        du=0;
        while(i<len&&str[i]>='0'&&str[i]<='9'){
            du=du*10+str[i]-'0';
            i++;
            //cout<<du<<endl;
        }
        in[k++]=du;
    }
    return k;
}
int ans,du;
void build(int L,int R,int l,int r,int value)
{
    int p=L;
    while (in[p] != post[r])++p;
    if (p>L) build(L,p-1,l,l+p-L-1,value+post[r]);
    if (p<R) build(p+1,R,l+p-L,r-1,value+post[r]);
    if (l==r) {
        if(ans>post[l]+value){
            ans=post[l]+value;
            du=post[l];
        }
        else if(ans==post[l]+value&&du>post[l])
           ans=post[l];
    }
}
int main(){
	while(getline(cin,str)){
        memset(in,0,sizeof(in));
        memset(post,0,sizeof(post));
        //cout<<str<<endl;
        int T=trans();
        for(int i=0;i<T;i++){
            scanf("%d",&post[i]);
        }
        /*
        for(int i=0;i<T;i++)
            cout<<in[i]<<" ";
        cout<<endl;
        for(int i=0;i<T;i++){
            cout<<post[i]<<" ";
        }*/
        ans=0x3f3f3f3f;
        du=-1;
        build(0,T-1,0,T-1,0);
        cout<<du<<endl;
        getchar();
	}
	return 0;
}
