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
  ll l,r,i,j,n;
  cin>>n;
  string s; cin>>s;
  vector<ll>vo,vz;
  ll o=0,z=0,mz=0,mo=0;
  for(i=0;i<n;i++){
    if(s[i]=='0'){
      z++;
    }
    else{
      if(z>1)vz.pb(z);
      if(z>mz)mz=z;
      z=0;
    }
  }
  if(z>mz)mz=z;
  if(z>1)vz.pb(z);
  for(i=0;i<n;i++){
    if(s[i]=='1'){
      o++;
    }
    else{
      if(o>1)vo.pb(o);
      if(o>mo)mo=o;
      o=0;
    }
  }
  if(o>mo)mo=o;
  if(o>1)vo.pb(o);
  mo=0;mz=0;
  for(i=0;i<vo.size();i++)mo+=(vo[i]-1);
  for(i=0;i<vz.size();i++)mz+=(vz[i]-1);
  cout<<max(mo,mz)<<"\n";
  return;
  // if(max(mo,mz)-1>2){
  //   cout<<max(mo,mz)<<"\n";return;
  // }
  // cout<<max(mo,mz)-1<<"\n";
  // if(l*1.0>=(r*1.0+1.0)/2.0){
  //   cout<<"YES\n";
  //   return;
  // }
  // cout<<"NO\n";
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