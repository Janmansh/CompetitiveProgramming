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
  ll a,b,x,y,i,j,n;
  cin>>n>>x>>y;
  if(n==2){
    cout<<x<<" "<<y<<"\n";return;
  }
  ll diff=y-x;
    ll modu=n-1;
    while(diff%modu)
    {
        modu=modu-1;
    }
    ll k=diff/modu;
    ll sum=x;i=0;
    while(sum!=y){
      cout<<sum<<" ";
      sum+=k;
      i++;
    }
    cout<<y<<" ";
    i++;
    sum=x;ll s=y;
    while(i<n){
      if(sum-k>0){sum-=k;cout<<sum<<" ";}
      else{y+=k;cout<<y<<" ";}
      i++;
    }
    cout<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  t=1;
  cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}