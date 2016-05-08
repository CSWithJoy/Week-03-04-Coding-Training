#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
string str1[1000];
string str2[1000];
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
        int n;
        scanf("%d",&n);getchar();
        for(int i=0;i<n;i++){
            getline(cin,str1[i]);
        }
        for(int j=0;j<n;j++)
        {
            getline(cin,str2[j]);
        }
        int i=n-1,j=n-1;
        for(;i>=0&&j>=0;){
            if(str1[i]==str2[j])
            {
                i--;
                j--;
            }
            else{
                i--;
            }
        }
        while(j>=0)cout<<str2[j--]<<endl;
        cout<<endl;
	}
	return 0;
}
