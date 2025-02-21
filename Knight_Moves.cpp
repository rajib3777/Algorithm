#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int,int>> d = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int N,M;
int Ki,Kj,Qi,Qj;

bool valid(int i, int j)
{
    return(i >= 0 && i < N && j >= 0 && j < M);
}

int bfs(int sr,int sc)
{
    queue<pair<int,int>> pq;
    pq.push({sr,sc});
    vis[sr][sc] = true;
    dis[sr][sc] = 0;

    while(!pq.empty())
    {
        pair<int,int>par = pq.front();
        pq.pop();

        if(par.first == Qi && par.second == Qj)
            return dis[par.first][par.second];

        for(int i =0; i < 8;i++)
        {
            int cr = par.first + d[i].first;
            int cc = par.second + d[i].second;

            if(valid(cr,cc) && !vis[cr][cc])
            {
                vis[cr][cc] = true;
                dis[cr][cc] = dis[par.first][par.second] + 1;
                pq.push({cr,cc});
            }
        }
    }
    return -1;
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        cin >> Ki >> Kj;
        cin >> Qi >> Qj;

        memset(vis,false,sizeof(vis));

        for(int i = 0;i < N; i++)
           for(int j = 0; j < M;j++)
               dis[i][j] = -1;

        cout << bfs(Ki,Kj) << endl;

    }
    
    return 0;
}