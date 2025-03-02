#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool vis[1005];

void dfs(int X)
{
    vis[X] = true;

    for(int child : adj_list[X])
    {
        if(!vis[child])
        {
            cout << child << " ";
            dfs(child);
        }
    }
}

int main()
{
    int N,E;
    cin >> N >> E;
    int A,B;

    while(E--)
    {
        cin >> A >> B;

        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }


    for(int i = 0;i < 1005 ; ++i)
    {
        if(!adj_list[i].empty())
        {
            (adj_list[i].rbegin(),adj_list[i].rend());
        }
    }

    int Q;
    cin >> Q;

    for(int i = 0;i < Q ; ++i)
    {
        int X;
        cin >> X;

        memset(vis,false,sizeof(vis));

        dfs(X);

        cout << endl;

    }

    return 0;
}