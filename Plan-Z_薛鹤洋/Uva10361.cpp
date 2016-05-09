/*
字符串的简单操作，注意各种输入的问题还有输出格式即可。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

//const int maxn=;

using namespace std;

int t,s2l,s2r,s4l,s4r,cnt1,cnt2;

int main()
{
        scanf("%d",&t);
        getchar();
        for(int h=1;h<=t;h++){
        string a,b;
        getline(cin,a);
        s2l=0,s2r=0,s4l=0,s4r=0,cnt1=0,cnt2=0;
        for(size_t i=0;i<a.length();i++){
                if(a[i]!='<'&&a[i]!='>') cout<<a[i];
                if(a[i]=='<'){
                        cnt1++;
                        if(cnt1==1){
                                s2l=i;
                        }
                        if(cnt1==2){
                                s4l=i;
                        }
                }
                if(a[i]=='>'){
                       cnt2++;
                       if(cnt2==1){
                        s2r=i;
                       }
                       if(cnt2==2){
                        s4r=i;
                       }
                }
        }
        cout<<endl;
        getline(cin,b);
        for(size_t i=0;i<b.length();i++){
                if(b[i]!='.') cout<<b[i];
                else break;
        }
        for(int i=s4l;i<=s4r;i++){
                if(a[i]!='<'&&a[i]!='>') cout<<a[i];
        }
        for(int i=s2r;i<=s4l;i++){
                if(a[i]!='<'&&a[i]!='>') cout<<a[i];
        }
        for(int i=s2l;i<=s2r;i++){
                if(a[i]!='<'&&a[i]!='>') cout<<a[i];
        }
        for(size_t i=s4r;i<a.length();i++) {
                if(a[i]!='<'&&a[i]!='>') cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
