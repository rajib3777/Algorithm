#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int a,b,w;
    Edge(int a,int b,int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int dis[1005];
int a,b,w;
int n,e;
vector<Edge> edge_list;
bool bellman(int src)
{
    dis[src] = 0;

    for(int i = 0;i < n-1; i++)
    {
        for(auto ed : edge_list)
        {
            a = ed.a;
            b = ed.b;
            w = ed.w;

            if(dis[a] != INT_MAX && dis[a] + w < dis[b])
                dis[b] = dis[a] + w;
        }
    }

    for(auto ed : edge_list)
    {
        a = ed.a;
        b = ed.b;
        w = ed.w;

        if(dis[a] != INT_MAX && dis[a] + w < dis[b])
        {
            cout << "Negative Cycle Detected" << endl;
            return false;
        }

    }
    return true;
}

int main()
{
    cin >> n >> e;
    while(e--)
    {
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a,b,w));
    }
    
    for(int i = 1; i <= n ;i++)
        dis[i] = INT_MAX;

    int src;
    cin >> src;

    if(!bellman(src))
        return 0;

    int T;
    cin >> T;
    while(T--)
    {
        int d;
        cin >> d;

        if(dis[d] == INT_MAX)
           cout << "Not Possible" << endl;
        else
           cout << dis[d] << endl;
    }

    return 0;
}