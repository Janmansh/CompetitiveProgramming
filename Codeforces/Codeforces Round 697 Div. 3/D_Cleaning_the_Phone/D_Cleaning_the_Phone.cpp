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
  ll n,m,i,j; cin>>n>>m;
  ll a[n],b[n];
  for(i=0;i<n;i++){
      cin>>a[i];
  }
  for(i=0;i<n;i++)cin>>b[i];
  vector<int>o,t;
  o.pb(0ll);
  t.pb(0ll);
  for(i=0;i<n;i++){
    if(b[i]%2) o.pb(a[i]);
    else  t.pb(a[i]);
  }
  sort(o.begin()+1,o.end(),greater<int>());
  sort(t.begin()+1,t.end(),greater<int>());
  for(i=1;i<t.size();i++)t[i]+=t[i-1];
  for(i=1;i<o.size();i++)o[i]+=o[i-1];
  ll ans=10000000000;
  for(i=0;i<t.size();i++){
    ll x = t[i];
    int index = lower_bound(o.begin(),o.end(), m-x) - o.begin();
    if(index!=o.size()){
      ans=min(ans,2*i+index);
    }
  }
  if(ans==10000000000)ans=-1;
  cout<<ans<<"\n";
  // ll ans=0,answer=0;
  // for(i=0;i<n;i++){
  //     ans+=v[i].second;
  //     if(ans>m){
  //         break;
  //     }
  //     answer+=v[i].first;
  // }
  // if(i==n){
  //     cout<<"-1\n";
  // }
  // else{
  //     cout<<answer<<"\n";
  // }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
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