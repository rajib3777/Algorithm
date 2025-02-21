#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int,int> parent[1005][1005];
int level[1005][1005];
vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int N,M;
int si,sj,di,dj;

bool valid(int i, int j)
{
    return(i >= 0 && i < N && j >= 0 && j < M);
}

void bfs(int sr,int sc)
{
    queue<pair<int,int>> pq;
    pq.push({sr,sc});
    vis[sr][sc] = true;
    level[sr][sc] = 0;

    while(!pq.empty())
    {
        pair<int,int>par = pq.front();
        pq.pop();

        for(int i =0; i < 4;i++)
        {
            int cr = par.first + d[i].first;
            int cc = par.second + d[i].second;

            if(valid(cr,cc) && !vis[cr][cc] && (grid[cr][cc] == '.' || grid[cr][cc] == 'R' || grid[cr][cc] == 'D'))
            {
                pq.push({cr,cc});
                vis[cr][cc] = true;
                level[cr][cc] = level[par.first][par.second] + 1;
                parent[cr][cc] = {par.first,par.second};
            }
        }
    }
}


int main()
{
    cin >> N >> M;
    for(int i = 0; i < N;i++)
        for(int j = 0; j < M;j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
        
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    
    for(int i = 0; i < N;i++)
        for(int j = 0; j < M; j++)
           parent[i][j] = {-1,-1};
    bfs(si,sj);

    int x = di,y = dj;
    while(parent[x][y].first != -1 && parent[x][y].second != -1)
    {
        pair<int,int> par = parent[x][y];
        x = par.first;
        y = par.second;

        if(grid[x][y] == 'R')
        {
            break;
        }
        grid[x][y] = 'X';
    }

    for(int i = 0; i < N;i++)
    {
        for(int j = 0; j < M ;j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}