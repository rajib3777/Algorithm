#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int N,M;
int sr,sc;

bool valid(int i, int j)
{
    return(i >= 0 && i < N && j >= 0 && j < M);
}

void dfs(int sr,int sc )
{
    vis[sr][sc] = true;

    for(int i = 0; i < 4 ; i++)
    {
        int cr = sr + d[i].first;
        int cc = sc + d[i].second;

        if(valid(cr,cc) && !vis[cr][cc] && grid[cr][cc] == '.')
        {
            dfs(cr,cc);
        }

    }
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

    int count = 0;

    for(int i = 0;i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            if(grid[i][j] == '.')
            {
                if(!vis[i][j])
                {
                    count++;
                    dfs(i,j);
                }
            }
        }
    }

    cout << count << endl;


    return 0;

}