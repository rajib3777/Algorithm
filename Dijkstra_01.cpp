#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1005];
int dis[1005];
int n,e;
void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,src});
    dis[src] = 0;

    while(!q.empty())
    {
        auto par = q.top();
        q.pop();
        auto par_node = par.second;
        auto par_dis = par.first;
        for(auto child : adj[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if(par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                q.push({dis[child_node],child_node});

            }
        }
    }
}

int main()
{
    cin >> n >> e;

    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    fill(dis, dis + 1005, INT_MAX); 
    int src;
    cin >> src;

    dijkstra(src);

    for(int i = 0 ; i <= n; i++)
    {
        if (dis[i] == INT_MAX)
            cout << "node " << i << " -> distance: INF" << endl;
        else
            cout << "node " << i << " -> distance: " << dis[i] << endl;
    }

    return 0;
}