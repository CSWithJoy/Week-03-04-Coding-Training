#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	string str1,str2;
	int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        getline(cin,str1);
        //cout<<str1<<endl;
        //getchar();
        getline(cin,str2);
        //cout<<str2<<endl;
        int flag;
        flag=1;
        string a1,b1,a2,b2,a3,b3,a4;
        string res1,res2;
        int len1=str1.length();
        int len2=str2.length();
        int i;
        for(i=0;i<len1;){
            if(str1[i]=='<'&&flag==1){
                i++;
                while(str1[i]!='>'&&i<len1){
                    a1+=str1[i];
                    i++;
                }
                flag=0;
                i++;
                while(str1[i]!='<'&&i<len1){
                    a2+=str1[i];
                    i++;
                }
                i++;
                while(str1[i]!='>'&&i<len1){
                    a3+=str1[i];
                    i++;
                }
                i++;
                while(i<len1){
                    a4+=str1[i];
                    i++;
                }
            }
            else{
                res1+=str1[i];
                i++;
            }
        }
        for(i=0;i<len2;i++){
            if(str2[i]=='.'&&str2[i+1]=='.')
                break;
            else
                res2+=str2[i];
        }
        if(res1.length())cout<<res1;
        cout<<a1<<a2<<a3<<a4<<endl;
        if(res2.length())cout<<res2;
        cout<<a3<<a2<<a1<<a4<<endl;
    }
	return 0;
}
