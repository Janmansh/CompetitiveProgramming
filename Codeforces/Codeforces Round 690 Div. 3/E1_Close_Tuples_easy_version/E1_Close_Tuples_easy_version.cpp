#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007

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


void solve(){
  ll n,i,j; cin>>n; ll a[n]; for(i=0;i<n;i++)cin>>a[i];
  ll f[n+1]={0};
  for(i=0;i<n;i++)f[a[i]]++;
  ll ans=0;
  for(i=1;i<=n;i++){
    int x=f[i];
    ans+=((x*(x-1)*(x-2))/6);
  }
  for(i=1;i<n;i++){
    int x=f[i];
    int y=f[i+1];
    ans+=((x*y*(x+y-2))/2);
  }
  for(i=1;i<n-1;i++){
    int x=f[i];
    int y=f[i+2];
    ans+=((x*y*(x+y-2))/2);
  }
  for(i=1;i<n-1;i++){
    int x=f[i];
    int y=f[i+1];
    int z=f[i+2];
    ans+=(x*y*z);
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}