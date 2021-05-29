#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
  ll n,i,j,k;cin>>n;string s[n];
  for(i=0;i<n;i++)cin>>s[i];
  ll a[26]={0};
  for(i=0;i<n;i++){
    for(j=0;j<s[i].size();j++){
      a[s[i][j]-'a']++;
    }
  }
  for(i=0;i<26;i++){
    if(a[i]%n!=0){
      cout<<"NO\n";return;
    }
  }
  cout<<"YES\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  cin >> t;  // number of test cases
  while (t--){
    solve();
  }
  return 0;
}