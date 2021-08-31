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
    string s;
    cin>>s;
    ll ans = INT_MAX, i, j, n = s.length();
    int k;
    cin>>k;
    vector<vector<int>>adj(27);
    for(i=0;i<k;i++){
        char x, y;
        cin>>x>>y;
        //cout << x << " " << y << "\n";
        adj[x-'A'].pb(y-'A');
    }
    vector<vector<int>>dis(27, vector<int>(27, -1));
    for(i=0;i<26;i++){
        vector<int>vis(27, 0);
        queue<int>q;
        q.push(i);
        vis[i] = 1;
        dis[i][i] = 0;
        int l = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int v = q.front();
                q.pop();
                for(j=0;j<adj[v].size();j++){
                    if(vis[adj[v][j]]){
                        continue;
                    }
                    else{
                        q.push(adj[v][j]);
                        vis[adj[v][j]] = 1;
                        dis[i][adj[v][j]] = l;
                    }
                }
            }
            l++;
        }
    }
    //cout << dis[1][0] << " " << dis[2][0] << "\n";
    for(i=0;i<26;i++){
        int c = 0;
        for(j=0;j<n;j++){
            if(s[j] == 'A' + i)continue;
            if(dis[s[j]-'A'][i] == -1){
                c = -1;
                break;
            }
            c += dis[s[j] - 'A'][i];
        }
        if(c!=-1){
            //if(c<ans)cout<<i<<"\n";
            ans = min(ans, c);
        }
    }
    //for(i=0;i<26;i++)cout << dis[i][22] << " ";
    if(ans == INT_MAX){
        cout << "-1\n";return;
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
    ll x = 1;
    while (t--){
        cout << "Case #" << x <<": ";
        x++;
        solve();
    }
    return 0;
}
