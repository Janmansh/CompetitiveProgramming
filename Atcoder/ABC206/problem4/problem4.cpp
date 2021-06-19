#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];
vector<vector<int>>tree(200006);
vector<int>vis(200006,0);
int c = 0;

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

void dfs(int root){
  if(vis[root])return;
  vis[root]=1;
  c++;
  for(int i=0;i<tree[root].size();i++){
    if(vis[tree[root][i]])continue;
    dfs(tree[root][i]);
  }
  return;
}

void solve(){
  ll n,i,j;
  cin>>n;
  ll a[n];
  //map<int,int>m;
  for(i=0;i<n;i++){
    cin>>a[i];
    //m[a[i]]++;
  }
  ll f[n]={0};
  for(i=0;i<n/2;i++){
    if(a[i]!=a[n-i-1]){
      tree[a[i]].pb(a[n-i-1]);
      tree[a[n-i-1]].pb(a[i]);
    }
    else{
      f[i]=1;
    }
  }
  int ans=0;
  for(i=0;i<n/2;i++){
    if(f[i] or vis[a[i]])continue;
    c=0;
    dfs(a[i]);
    if(c>1)ans+=(c-1);
  }
  cout<<ans;
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  //srand(time(0));
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    solve();
  }
  return 0;
}