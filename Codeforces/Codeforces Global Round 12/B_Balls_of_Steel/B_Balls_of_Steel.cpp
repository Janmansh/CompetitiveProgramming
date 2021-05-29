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
  ll n,i,k,j; cin>>n>>k;
  ll x[n],y[n];
  for(i=0;i<n;i++)cin>>x[i]>>y[i];
  ll d=0;
  for(i=0;i<n;i++){
      int f=0;
      for(j=0;j<n;j++){
          if(i==j)continue;
          if(abs(x[j]-x[i])+abs(y[j]-y[i])>k){
              f=1;
              break;
          }
      }
      if(f)continue;
      else{cout<<"1\n";return;}
  }
  cout<<"-1\n";
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