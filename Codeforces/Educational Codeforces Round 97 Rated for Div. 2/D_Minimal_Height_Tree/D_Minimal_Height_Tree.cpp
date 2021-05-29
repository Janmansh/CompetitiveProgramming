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
  ll n,i,j;
  cin>>n; ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll ans=1,c=1,k=0,f=0;
  vector<vector<ll>>v(n+1);
  v[a[0]].pb(a[1]);
  ll par=1,t=1;
  for(i=2;i<n;i++){
    if(a[i]>a[i-1]){
      c++;
    }
    if(a[i]<a[i-1]){
      k++;
      if(f==0){
        ans++;
        t=c;
        f=1;
        c=1;
      }
      else c++;
      if(k==t){
        f=0;
        k=0;
        continue;
      }
    }
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