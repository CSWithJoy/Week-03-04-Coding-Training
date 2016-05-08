//UVa10152一个堆，每次可以把堆里的一个元素移到顶部，输出使堆变成目标堆要依次移动那些元素
//从堆的底部向上遍历，和目标堆一样的就跳过，不一样的就是要移动的，遍历结束后要移动的肯定为目标堆的顶部的几个，逆序输出就可以了。
#include <iostream>
#include<queue>
#include<stack>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        stack<string> w_guike;
        stack<string> r_guike;
        string tuil;
        getline(cin,tuil);
        int n = N;
        while(N--)
        {
            getline(cin,tuil);
            w_guike.push(tuil);
            //cout << N <<endl;
        }
        while(n--)
        {
            getline(cin,tuil);
            r_guike.push(tuil);
            //cout<<n<<endl;
        }
        while(!w_guike.empty())
        {
            if(w_guike.top() == r_guike.top())
            {
                w_guike.pop();
                r_guike.pop();
            }
            else
            {
                w_guike.pop();
            }
        }
        while(!r_guike.empty())
        {
            cout<<r_guike.top()<<endl;
            r_guike.pop();
        }
        cout<<endl;
    }
    return 0;
}
