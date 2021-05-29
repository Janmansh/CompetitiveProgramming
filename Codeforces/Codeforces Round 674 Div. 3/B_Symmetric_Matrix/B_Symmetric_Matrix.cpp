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
  cin>>n>>m;
  ll a[n][2][2],f=0;
  for(i=0;i<n;i++){
    cin>>a[i][0][0]>>a[i][0][1]>>a[i][1][0]>>a[i][1][1];
    if(a[i][0][0]==a[i][1][0]&&a[i][0][1]==a[i][0][0]&&a[i][0][0]==a[i][1][1])f=1;
    if(a[i][0][1]==a[i][1][0])f=1;
  }
  if(m%2){
    cout<<"NO\n";return;
  }
  if(f==1){
    cout<<"YES\n";return;
  }
  cout<<"NO\n";
  return;
  if(n<=0){
    cout<<"1\n";return;
  }
  ll ans=1;
  ans+=(n/x);
  if(n%x)ans++;
  cout<<ans<<"\n";
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