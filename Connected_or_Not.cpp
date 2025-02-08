#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
int A,B;

void connection()
{
    int Q;
    cin >> Q;

    for(int i = 0 ; i < Q ; ++i)
    {
        cin >> A >> B;

        if(A == B)
        {
            cout << "YES" << endl;
            continue;
        }

        bool connected = false;

        for(int child : adj_list[A])
        {
            if(child == B)
            {
                connected = true;
                break;
            }
        }

        if(connected)
           cout << "YES" << endl;
        else
           cout << "NO" << endl;
    }

}

int main()
{
    int N,E;
    cin >> N >> E;

    for(int i = 0;i < E; ++i)
    {
        cin >> A >> B;

        adj_list[A].push_back(B);
    }

    connection();
    


    return 0;
}