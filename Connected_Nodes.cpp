#include<bits/stdc++.h>
using namespace std;

set<int,greater<int>> adj_list[1005];

void connected_with(int& X)
{
    if(adj_list[X].empty())
        cout << -1 << endl;
    else
        for(int child : adj_list[X])
           cout << child << endl;

        cout << endl;
}

int main()
{
    int N,E;
    cin >> N >> E;
    int A,B;

    while(E--)
    {
        cin >> A >> B;

        adj_list[A].insert(B);
        adj_list[B].insert(A);
    }

    int Q;
    cin >> Q;

    while(Q--)
    {
        int X;
        cin >> X;
        connected_with(X);
    }


    return 0;
}