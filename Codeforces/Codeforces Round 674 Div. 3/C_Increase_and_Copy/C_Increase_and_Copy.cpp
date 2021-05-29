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
  ll n,x,i,m;
  cin>>n;
  ll f=0;
  if(n==1){cout<<"0\n";return;
  }
  if(n==2){
    cout<<"1\n";return;
  }
  if(n==3){
    cout<<"2\n";return;
  }
  ll y=sqrt(n);
  
  if(n%y==0){
    cout<<n/y+y-2<<"\n";
  }
  else{
    cout<<y-1+n/y<<"\n";
  }
  return;
  x=100000000000000;
  for(i=2;i<=sqrt(n);i++){
    if(n%i==0){f=1;
        x=min(x,i-2+n/i);}
  }
  if(f==0){
    ll ans=1;
    x=10000000000000000;
    n--;
    for(i=2;i<=sqrt(n);i++){
      if(n%i==0){
        f=1;
        x=min(x,i-1+n/i);
      }
    }
    cout<<x<<"\n";
  }
  else{
    cout<<x<<"\n";
  }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;  
  while (t--){
    //cout<<t<<"\n";
    solve();
  }
  return 0;
}