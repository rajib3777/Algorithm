#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool vis[1005];

void dfs(int A)
{
    vis[A] = true;

    for(int child : adj_list[A])
    {
        if(!vis[child])
        {
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
    }

    memset(vis,false,sizeof(vis));

    int Q;
    cin >> Q;

    for(int i = 0;i < Q ; ++i)
    {
        cin >> A >> B;

        memset(vis,false,sizeof(vis));

        dfs(A);

        if(vis[B])
           cout << "YES" << endl;
        else
           cout << "NO" << endl;

        
    }


    return 0;
}