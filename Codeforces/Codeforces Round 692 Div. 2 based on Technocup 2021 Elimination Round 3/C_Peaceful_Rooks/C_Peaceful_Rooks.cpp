#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Mod 1000000007

pair<int,int> P[100001];
vector<int> Adj[100001];
vector<int> Visited(100001);

void makeFree(int i)
{
    for(int j=0; j<Adj[i].size(); j++)
    {
        if(Adj[i][j] != 0)
        {
            int v = Adj[i][j];
            Adj[i][j] = 0;
            makeFree(v);
        }
    }
}

void DFS(int i, int &c)
{
    if(Visited[i])
        return;
    Visited[i] = 1;
    c++;
    for(int j=0; j<Adj[i].size(); j++)
    {
        if(Adj[i][j] != 0)
        {
            DFS(Adj[i][j], c);
        }
    }
}

signed main()
{
    Fio;
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;
        // cout << "Hello";
        for(int i=1; i<=M; i++)
        {
            Adj[i].clear();
            Visited[i] = 0;
        }
        // cout << "Hello";
        for(int i=1; i<=M; i++)
            cin >> P[i].first >> P[i].second;

        vector<int> row(N+1, 0), col(N+1, 0);
        int count = 0;
        // cout << "Hello";
        for(int i=1; i<=M; i++)
        {
            int x = P[i].first;
            int y = P[i].second;
            row[x] = i;
            col[y] = i;
            if(x == y)
                count++;
        }
        // cout << "Hello";
        for(int i=1; i<=M; i++)
        {
            int x = P[i].first;
            int y = P[i].second;
            if(x == y)
                continue;
            Adj[i].push_back(row[y]);
            Adj[i].push_back(col[x]);
        }
        // cout << "Hello";
        vector<int> Free(M+1, 0);
        for(int i=1; i<=M; i++)
        {
            int x = P[i].first;
            int y = P[i].second;
            if(x == y)
                continue;
            if(Adj[i][0] == 0 || Adj[i][1] == 0)
                Free[i] = 1;
        }
        // cout << "Hello";
        for(int i=1; i<=M; i++)
        {
            int x = P[i].first;
            int y = P[i].second;
            if(x == y)
                continue;
            if(Free[i])
                makeFree(i);
        }    
        // cout << "Hello";
        int components = 0;
        for(int i=1; i<=M; i++)
        {
            int x = P[i].first;
            int y = P[i].second;
            if(x == y)
                continue;
            if(!Visited[i])
            {
                int c = 0;
                DFS(i, c);
                if(c > 1)
                    components++;
            }
        }   

        cout << M - count + components << endl; 
        
    }
}