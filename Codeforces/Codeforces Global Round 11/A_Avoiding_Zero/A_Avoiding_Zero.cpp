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
  ll n,i,j;cin>>n; ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll k=0;
  sort(a,a+n,greater<ll>());
  for(i=0;i<n;i++){
    k+=a[i];
    // if(k+a[i]==0&&i!=n-1){
    //   ll temp=a[i]
    // }
    // k+=a[i];
    // if(k==0){
    //   cout<<"NO\n";return;
    // }
  }
  k=0;ll f=1;
  for(i=0;i<n;i++){
    k+=a[i];
    if(k==0){f=0;break;}
  }
  if(f){
    cout<<"YES\n";
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";return;
  }
  sort(a,a+n);
  k=0;
  for(i=0;i<n;i++){
    k+=a[i];
    if(k==0){cout<<"NO\n";return;}
  }
  cout<<"YES\n";
    for(i=0;i<n;i++)cout<<a[i]<<" ";
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