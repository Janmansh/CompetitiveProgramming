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
  cin>>n; ll a[n]; for(i=0;i<n;i++)cin>>a[i];
  //sort(a,a+n);
  ll o=0,z=0;
  for(i=0;i<n;i++){
    if(a[i]==1)o++;
  }
  if(o<=n/2){
    cout<<n-o<<"\n";
    for(i=0;i<n;i++){
      if(a[i]==0){
        cout<<a[i]<<" ";
      }
    }
    cout<<"\n";return;
  }
  if(o%2==0){
    cout<<o<<"\n";
    for(i=0;i<n;i++){
      if(a[i]==1){
        cout<<a[i]<<" ";
      }
    }
    cout<<"\n";return;
  }
  cout<<o-1<<"\n";
  j=0;
  for(i=0;i<n;i++){
    if(a[i]==1&&j==0)j++;
    else if(a[i]==1){
      cout<<a[i]<<" ";
    }
  }
  cout<<"\n";return;
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