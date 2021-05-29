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
  ll x,y,k,i,j,n;
  cin>>n;
  ll a[n],l[n];
  ll ans=0,f=0;
  for(i=0;i<n;i++)cin>>a[i];
  ll o=0,z=0;
  vector<int>v;
  for(i=0;i<n;i++){
    if(a[i]==1&&z==0)o++;
    else if(a[i]==0&&o==0)z++;
    else if(a[i]==1&&z!=0){
      //v.pb(z);
      z=0;o++;
    }
    else{
      v.pb(o);o=0;z++;
    }
  }
  if(o!=0)v.pb(o);o=0;
  for(i=0;i<v.size();i++){
    if(i==0&&a[0]==1&&v[i]%3!=0){ans+=(v[i]/3);ans++;}
    else{
      ans+=(v[i]/3);
    }
  }
  cout<<ans<<"\n";
  // for(i=0;i<n;i++){
  //   if(a[i]==1&&f==0){
  //     ans++;
  //     f=1;
  //     if(i+1<n&&a[i+1]==0)i++;
  //   }
  //   else if(a[i]==1&&f==1){
  //     if(i+1<n&&a[i+1]==1){
  //       i++;
  //     }
  //     f=0;
  //   }
  //   else if(a[i]==0&&f==0){
  //     f=1;
  //     if(i+1<n&&a[i+1]==0)i++;
  //   }
  //   else{
  //     f=0;
  //     if(i+1<n&&a[i+1]==1){
  //       i++;
  //     }
  //   }
  // }
  // cout<<ans<<"\n";
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