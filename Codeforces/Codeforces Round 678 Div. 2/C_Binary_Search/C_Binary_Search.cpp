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
  ll i,j,n,x,p;cin>>n>>x>>p;
  //ll a[n];
  //for(i=0;i<n;i++)a[i]=i;
  ll le=0,re=0;
  ll l=0,r=n;
  ll less=x-1;
  ll more=n-x;
  while(l<r){
    ll mid=(l+r)/2;
    //if(mid>=p)break;
    if(mid<=p){
      if(mid!=p)le++;
      l=mid+1;
    }
    else{
      re++;
      r=mid;
    }
  }
  ll ans=1;
  ll k1=fact[re];
  k1*=(nCr(more,re,mod));
  k1%=mod;
  ans*=k1;ans%=mod;
  k1=fact[le]; k1*=nCr(less,le,mod); k1%=mod;
  ans*=k1; ans%=mod;
  k1=fact[n-1-le-re];
  ans*=k1;
  ans%=mod;
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
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