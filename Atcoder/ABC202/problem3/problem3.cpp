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
  ll n,i,j;
  cin>>n;
  ll a[n+1],b[n+1],c[n+1];
  //map<int,vector<int>>m;
  for(i=1;i<=n;i++)cin>>a[i];
  for(i=1;i<=n;i++){
    cin>>b[i];
    //m[b[i]].pb(i);
  }
  ll f[n+1]={0},ff[n+1]={0};
  for(i=1;i<=n;i++){
    cin>>c[i];
    f[c[i]]++;
    ff[a[i]]++;
  }
  sort(a+1,a+n+1);
  ll ans=0;
  for(i=1;i<=n;i++){
    ans+=(ff[b[i]]*f[i]);
    // vector<int>k = m[a[i]];
    // if(k.size()==0)continue;
    // for(j=0;j<k.size();j++){
    //   ans+=f[k[j]];
    // }
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