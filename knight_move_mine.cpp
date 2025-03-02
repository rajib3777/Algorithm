int bfs(int sr,int sc)
{
    queue<pair<int,int>> pq;
    pq.push({sr,sc});
    vis[sr][sc] = true;
    int step = 0;

    while(!pq.empty())
    {
        int sz = pq.size();
        while(sz--)
        {
            pair<int,int> par = pq.front();
            pq.pop();

            if(par.first == Qi && par.second == Qj)
                return step;

            for(int i =0; i < 8;i++)
            {
                int cr = par.first + d[i].first;
                int cc = par.second + d[i].second;

                if(valid(cr,cc) && !vis[cr][cc])
                {
                    vis[cr][cc] = true;
                    pq.push({cr,cc});
                }
            }
        }
        step++;
    }
    return -1;

}