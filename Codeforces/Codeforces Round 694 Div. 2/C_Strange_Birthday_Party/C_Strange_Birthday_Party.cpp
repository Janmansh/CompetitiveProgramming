#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define double long double

//ll fact[200005];

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

// int gcd (int a, int b) {
//     return b ? gcd (b, a % b) : a;
// }

// ll inv(ll a, ll p){
// 	return powermod(a,mod-2);
// }
 
// ll nCr(ll n, ll r, ll p){
// 	if(r > n) return 0;
// 	ll t1 = fact[n];
// 	ll t2 = inv(fact[r],p);
// 	ll t3 = inv(fact[n-r],p);
 
// 	return (((t1*t2)%p)*t3)%p;
// }



void solve(){
  ll n,i,j,m; cin>>n>>m;
  ll k[n],c[m];
  for(i=0;i<n;i++)cin>>k[i];
  for(i=0;i<m;i++)cin>>c[i];
  vector<pair<int,int>>v;
  for(i=0;i<n;i++){
    v.pb(mp(k[i]-1,i));
  }
  sort(v.begin(),v.end());
  ll ans[n];
  for(i=0;i<n;i++)ans[i]=-1;
  j=0;
  for(i=n-1;i>=0;i--){
    if(j>v[i].first)break;
    ans[v[i].second]=c[j];
    j++;
  }
  ll answer=0;
  for(i=0;i<n;i++){
    if(ans[i]==-1){
      ans[i]=c[k[i]-1];
    }
    answer+=ans[i];
  }
  cout<<answer<<"\n";
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