#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int weight[1005];
int val[1005];
int knapsack(int i,int mx_weight)
{
    if(i < 0 || mx_weight <= 0)
       return 0;

    if(dp[i][mx_weight] != -1)
       return dp[i][mx_weight];

    if(weight[i] <= mx_weight)
    {
        int op1 = knapsack(i - 1,mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1,mx_weight);
        dp[i][mx_weight] = max(op1,op2);
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1,mx_weight);
    }
    return dp[i][mx_weight];
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n,w;
        cin >> n >> w;

        for(int i = 0; i < n;i++)
        {
            cin >> weight[i];
        }

        for(int i = 0; i < n;i++)
        {
            cin >> val[i];
        }

        memset(dp,-1,sizeof(dp));

        cout << knapsack(n - 1,w) << endl;
    }

    return 0;
}