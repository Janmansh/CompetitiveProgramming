#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];

ll powermod(ll x,ll y){
    if(y==0) return 1;
    ll temp = powermod( x,y/2 )%mod;
    if( y%2 ){
        return (((temp*temp)%mod)*x%mod);
    }
    return (temp*temp)%mod;
}

ll power(ll x,ll y){
    if(y==0) return 1;
    ll temp = power( x,y/2 );
    if( y%2 ){
        return (((temp*temp))*x);
    }
    return (temp*temp);
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

ll inv(ll a, ll p){
    return powermod(a,mod-2);
}
 
ll nCr(ll n, ll r, ll p){
    if(r > n) return 0;
    ll t1 = fact[n];
    ll t2 = inv(fact[r],p);
    ll t3 = inv(fact[n-r],p);
    return (((t1*t2)%p)*t3)%p;
}

int dfs(int r, vector<vector<int>>&adj, vector<int>&c, int p){
    int i, s1 = 0, s2 = 0, s = 0;
    for(i=0;i<adj[r].size();i++){
        if(adj[r][i] == p)continue;
        s = dfs(adj[r][i], adj, c, r);
        if(s>=s1){
            s2 = s1;
            s1 = s;
        }
        else{
            if(s>=s2){
                s2 = s;
            }        
        }
    }
    if(r == 1){
        return c[r] + s1 + s2;
    }
    else{
        return c[r] + s1;
    }
}

void solve(){
    ll n,i,j;
    cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>c(n+1);
    for(i=0;i<n;i++){
        cin>>j;
        c[i+1] = j;
    }
    for(i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cout << dfs(1, adj, c, 0) << "\n";
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
    ll x = 1;
    while (t--){
        cout << "Case #" << x <<": ";
        x++;
        solve();
    }
    return 0;
}
