#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int a,b,c;
    Edge(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005];
int a,b,c;
int n,e;
vector<Edge> edge_list;
void bellman(int src)
{
    dis[src] = 0;

    for(int i = 0;i < n-1; i++)
    {
        for(auto ed : edge_list)
        {
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if(dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    bool cycle = false;
    for(auto ed : edge_list)
    {
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if(dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            dis[b] = dis[a] + c;
            cycle = true;
            break;
        }

    }
}

int main()
{
    cin >> n >> e;
    while(e--)
    {
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
        edge_list.push_back(Edge(b,a,c));
    }

    memset(dis,-1,sizeof(dis));
    
    for(int i = 1; i <= n ;i++)
        dis[i] = INT_MAX;

    int src;
    cin >> src;
    bellman(src);

    for(int i = 0; i < n ; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}