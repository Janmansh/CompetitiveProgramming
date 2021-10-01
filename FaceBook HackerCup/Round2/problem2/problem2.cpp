#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

int n, l;
vector<vector<int>> adj;
vector<vector<int>>up;

int timer;
vector<int> tin, tout;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+100);
    tout.resize(n+100);
    l = ceil(log2(n+100));
    up.assign(n+100, vector<int>(l + 100));
    timer = 0;
    dfs(root, root);
}

void DFS1(int r, set<int>&values, int p, map<int, vector<int>>&lca_p, int &ans, vector<int>&vis){
    for(auto it:lca_p[r]){
        if(it>0){
            values.insert(it);
            // cout << r << " " << it << "\n";
        }
    }
    if(r>=n or r < 0)return;
    vis[r] = 1;
    for(int i=0;i<adj[r].size();i++){
        if(vis[adj[r][i]])continue;
        int c1 = values.size();
        DFS1(adj[r][i], values, r, lca_p, ans, vis);
        int c2 = values.size();
        if(c1 == c2){
            ans+=1;
        }
    }
    for(auto it:lca_p[r]){
        if(it<0){
            int temp = it;
            temp*=-1;
            if(values.find(temp) != values.end())values.erase(temp);
            // cout << r << " " << it << "\n";
        }
    }
    return;
}


void solve(){
    ll i,j;
    cin>>n;
    adj.resize(n+100);
    //map<pair<int,int>, int>edge;
    for(i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
        // edge[{a-1, b-1}] = 1;
        // edge[{b-1, a-1}] = 1;
    }
    map<int, vector<int>>m;
    for(i=0;i<n;i++){
        cin>>j;
        m[j].pb(i);
    }
    preprocess(0ll);
    map<int, vector<int>>lca_p;
    int c = 1;
    int ans = 0;
    for(auto it:m){
        int x = it.second[0];
        for(i=1;i<it.second.size();i++){
            int y = lca(x, it.second[i]);
            if(it.second[i] == y and y == x){
                continue;
            }
            if(x == y){
                lca_p[it.second[i]].pb(-1*c);
                lca_p[y].pb(c);
                c++;
                continue;
            }
            if(it.second[i] == y){
                lca_p[x].pb(-1*c);
                lca_p[y].pb(c);
                c++;
                x = y;
                continue;
            }
            lca_p[it.second[i]].pb(-1*c);
            lca_p[y].pb(c);
            c++;
            lca_p[x].pb(-1*c);
            lca_p[y].pb(c);
            c++;
            x = y;
        }
    }
    set<int>values;
    vector<int>vis(n+1, 0);
    DFS1(0ll, values, -1ll, lca_p, ans, vis);
    cout << ans << "\n";
    for(i=0;i<=n;i++)adj[i].clear();
    adj.clear();
    tin.clear();
    tout.clear();
    for(i=0;i<up.size();i++)up[i].clear();
    up.clear();
    return;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    cin>>t;
    // srand(time(0));
    // fact[0]=1;
    // for(int i=1;i<200001;i++){
    //     fact[i]=i*fact[i-1];
    //     fact[i]%=mod;
    // }
    int x = 1;
    while (t--){
        cout << "Case #" << x << ": ";
        x++;
        solve();
    }
    return 0;
}
