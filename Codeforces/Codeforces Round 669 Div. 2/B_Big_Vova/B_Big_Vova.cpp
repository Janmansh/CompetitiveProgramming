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
  sort(a,a+n);
  vector<int>b;
  ll x=*max_element(a, a+n);
  ll gc=x;
  set<int>s;
  ll max=0;
  for(i=0;i<n;i++){
    if(a[i]==x){
      s.insert(i);
      break;
    }
  }
  b.pb(x);
  while(b.size()<n){
    ll maxi=0;j=0;
    for(i=0;i<n;i++){
      if(s.find(i)!=s.end())continue;
      else{
        ll kk=__gcd(a[i],gc);
        if(kk>maxi){
          maxi=kk;
          j=i;
        }
      }
    }
    gc=maxi;
    s.insert(j);
    b.pb(a[j]);
    //if(b.size()==n-1)break;
    if(s.size()==n)break;
  }
  for(i=0;i<b.size();i++){
    cout<<b[i]<<" ";
  }
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