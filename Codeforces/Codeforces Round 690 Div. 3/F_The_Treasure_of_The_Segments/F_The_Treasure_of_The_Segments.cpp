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
  ll n,i,j; cin>>n; 
  vector<pair<int,int>>v;
  ll l,r;
  vector<int>le,ri;
  for(i=0;i<n;i++){
    cin>>l>>r;
    v.pb(mp(l,r));
    le.pb(l);
    ri.pb(r);
  }
  sort(le.begin(),le.end());
  sort(ri.begin(),ri.end());
  ll ans=n;
  for(i=0;i<n;i++){
    ll k1,k2;
    //auto it1 = lower_bound(ri.begin(),ri.end(),v[i].first);
    k1=distance(ri.begin(), lower_bound(ri.begin(),ri.end(),v[i].first));
    //it1--;
    //k1 = it1-ri.begin();
    k2=distance(le.begin(),upper_bound(le.begin(),le.end(),v[i].second));
    k2=n-k2;
    ans=min(ans,k1+k2);
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  fact[0]=1;
  for(int i=1;i<200001;i++){
    fact[i]=i*fact[i-1];
    fact[i]%=mod;
  }
  while (t--){
    solve();
  }
  return 0;
}