#include<bits/stdc++.h>
using namespace std;
int dp[10005];
bool reach(int current,int target)
{
    if(current == target)
        return true;
    if(current > target)
        return false;
    if(dp[current] != -1)
        return dp[current];
    
    return dp[current] = reach(current * 2,target) || reach(current + 3,target);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        for(int i = 0; i < 1005 ; i++)
        {
            dp[i] = -1;
        }

        if(reach(1,N))
           cout << "YES" << endl;
        else
           cout << "NO" << endl;
    }

    return 0;
}