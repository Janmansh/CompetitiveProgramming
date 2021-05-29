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
  ll n,i,j; cin>>n; ll a[n]; for(i=0;i<n;i++)cin>>a[i];
  ll pre=a[0],last=0;
  for(i=1;i<n-1;i++){
    a[i]-=last;
    if(a[i]<0){
      cout<<"NO\n";return;
    }
    if(a[i]<pre){
      pre=a[i];
    }
    if(a[i]>pre)last+=(a[i]-pre);
  }
  if(a[n-1]<last){
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
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