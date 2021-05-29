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


void solve(){
  ll n,i,j;cin>>n;
  ll a[n],b[n],c[n];
  vector<ll>p;
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n;i++)cin>>b[i];
  for(i=0;i<n;i++)cin>>c[i];
  if(n==1){
    cout<<a[0]<<"\n";return;
  }
  p.pb(a[0]);
  int f=0;
  for(i=1;i<n;i++){
      if(a[i]!=p[i-1])p.pb(a[i]);
      else if(b[i]!=p[i-1])p.pb(b[i]);
      else{
        p.pb(c[i]);
      }
  }
  if(p[n-1]==p[0]){
    if(a[n-1]!=p[0]&&a[n-1]!=p[n-2])p[n-1]=a[n-1];
    else if(b[n-1]!=p[0]&&b[n-1]!=p[n-2])p[n-1]=b[n-1];
    else{
      p[n-1]=c[n-1];
    }
  }
  for(i=0;i<n;i++)cout<<p[i]<<" ";
  cout<<"\n";
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