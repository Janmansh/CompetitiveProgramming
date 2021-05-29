#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int long long
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
  ll n,i,j,k;cin>>n;ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  if(n==1){
    cout<<a[i]-1<<"\n";return;
  }
  sort(a,a+n);
  ll x=pow(a[n-1]*1.0,1.0/(n-1.0));
  //ll y=a[n-1]-power(x,n-1);ll z=power(x+1,n-1)-a[n-1];
  ll ans=0,ans1=0,ans2=0;
    for(i=0;i<n;i++){
      ans1+=(abs(a[i]-power(x,i)));
    }
    //for(i=0;i<n;i++)ans2+=(abs(a[i]-power(x-1,i)));
    for(i=0;i<n;i++){
      if(power(x+1,i)<0){cout<<ans1<<"\n";return;}
      if(a[i]>power(x+1,i))ans+=(a[i]-power(x+1,i));
      else ans+=(power(x+1,i)-a[i]);
      if(ans<0){cout<<ans1<<"\n";return;}
    }
    cout<<min(ans,ans1)<<"\n";return;
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  t=1;
  //cin>>t;  // number of test cases
  while (t--){
    solve();
  }
  return 0;
}