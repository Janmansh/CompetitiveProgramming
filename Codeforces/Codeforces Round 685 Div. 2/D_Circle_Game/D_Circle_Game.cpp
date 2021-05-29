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
  ll n,i,j,k,d; cin>>d>>k;
  ll ans=0,x,y;
  for(i=0;i<=d/k+1;i++){
    x=i;
    y=sqrt(d*d-k*k*x*x);
    y/=k;
    y++;
    if(x+y>ans)ans=x+y;
  }
  if(ans%2){
    cout<<"Utkarsh\n";
  }
  else cout<<"Ashish\n";
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