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
  for(i=0;i<n;i++)cin>>a[i];for(i=0;i<n;i++)cin>>l[i];
  ll s=0,ans=n;
  for(i=0;i<n;i++){
    s+=a[i];
    if(s<0){
      ans=i+1;
    }
  }
  ll flag=1;
  for(i=0;i<n;i++)if(l[i]==0)flag=0;
  if(ans==0||flag||s<0){
    for(i=0;i<n;i++){
      cout<<a[i]<<" ";
    }
    cout<<"\n";return;
  }
  vector<int>v;
  for(i=0;i<n;i++){
    if(l[i]==0)v.pb(a[i]);
  }
  sort(v.begin(),v.end(),greater<int>());j=0;
  for(i=0;i<n;i++){
    if(l[i]==0){
      a[i]=v[j];
      j++;
    }
  }
  for(i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<"\n";
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