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
  ll n,i,j,p,k; cin>>n>>p>>k;string a;cin>>a;//ll a[n]; map<int,int>f;vector<vector<int>>m(n+1);
  //for(i=0;i<=n;i++)f[i]=0;
  ll x,y; cin>>x>>y;
  ll dp[n+1]={0};
  for(i=n-1;i>=0;i--){
      if(a[i]=='0')dp[i]+=x;
      if(i+k<n)dp[i]+=dp[i+k];
  }
  ll ans=1000000000000;
  for(i=p-1;i<n;i++){
      ll t=0;
      t+=dp[i]+(i-(p-1))*y;
      ans=min(t,ans);
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