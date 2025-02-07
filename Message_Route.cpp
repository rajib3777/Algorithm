#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    parent[src] = -1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n , e;


    for (int i = 0; i < 1005; i++)
    {
       adj_list[i].clear();
    }

    cin >> n >> e;

    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    memset(level, -1, sizeof(level));

    int src,dst;
    cin >> src >> dst;

    bfs(src);

    if (!vis[dst]) 
    {
       cout << "0" << endl;
       return 0;
    }

    
    vector<int> path;
    int node = dst;

    while(node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(),path.end());

    for(int x : path)
    {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}