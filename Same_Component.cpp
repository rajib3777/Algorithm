#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
vector<int> apar_size;
int N,M;
int Si,Sj,Di,Dj;

bool valid(int i, int j)
{
    return(i >= 0 && i < N && j >= 0 && j < M);
}

bool dfs(int sr,int sc)
{
    if(sr == Di && sc == Dj)
    {
        return true;
    }
    vis[sr][sc] = true;

    for(int i = 0; i < 4 ; i++)
    {
        int cr = sr + d[i].first;
        int cc = sc + d[i].second;

        if(valid(cr,cc) && !vis[cr][cc] && grid[cr][cc] == '.')
        {
            if(dfs(cr,cc)) 
               return true;
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
        }
    }
    memset(vis,false,sizeof(vis));
    
    cin >> Si >> Sj;
    cin >> Di >> Dj;

    if(dfs(Si,Sj))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}