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


void solve(){
    ll n,m,i,j;
    cin>>n>>m;
    ll s[m];
    for(i=0;i<m;i++)cin>>s[i];
    vector<vector<int>>v(n, vector<int>(m, 0));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int temp;
            cin>>temp;
            v[i][j] = temp;
        }
    }
    map<int, multiset<int, greater<int>>>val;
    int ans = 0;
    for(i=0;i<m;i++){
        val[s[i]].insert(0);
    }
    for(i=0;i<n;i++){
        vector<int>vis(m, 0);
        map<int, multiset<int, greater<int>>>val_temp;
        for(j=0;j<m;j++){
            if(val[v[i][j]].size()>0){
                vis[j] = 1;
                val_temp[v[i][j]].insert(*val[v[i][j]].begin());
                val[v[i][j]].erase(val[v[i][j]].begin());
            }
        }
        queue<int>q;
        for(auto it:val){
            for(auto it1:it.second)q.push(it1);
        }
        for(j=0;j<m;j++){
            if(vis[j])continue;
            val_temp[v[i][j]].insert(q.front() + 1);
            q.pop();
        }
        val = val_temp;
    }
    for(auto it:val){
        for(auto it1:it.second){
            ans += max(it1 - 1, 0ll);
        }
    }
    cout << ans << "\n";
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
