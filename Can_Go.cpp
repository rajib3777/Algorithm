#include<bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int N,M;
int sr,sc,dr,dc;

bool valid(int i, int j)
{
    return(i >= 0 && i < N && j >= 0 && j < M && grid[i][j] != '#');
}

bool bfs()
{
    queue<pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;

    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();

        if(par.first == dr && par.second == dc)
        {
            return true;
        }

        int par_i = par.first;
        int par_j = par.second;

        for(int i = 0; i < 4; i++)
        {

            int cr = par_i + d[i].first;
            int cc = par_j + d[i].second;

            if(valid(cr,cc) && !vis[cr][cc])
            {
                q.push({cr,cc});
                vis[cr][cc] = true;
            }

        } 
    }
    return false;
}

int main()
{
    cin >> N >> M;
    
    for(int i = 0;i < N; i++)
    {
        for(int j = 0;j < M ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
            {
                sr = i,sc = j;
            }
            else if(grid[i][j] == 'B')
            {
                dr = i,dc = j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    
    bool result = bfs();
    cout << (result ? "YES" : "NO" ) << endl;


    return 0;
}