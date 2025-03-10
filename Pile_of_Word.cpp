#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string a,b;
        cin >> a >> b;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a == b)
            cout << "YES" << endl;
        if(a.size() != b.size())
            cout << "NO" << endl;
    }


    return 0;
}