#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

// power function to take modulo
ll power(ll x,ll y){
  if(y==0) return 1;
  ll temp = power( x,y/2 )%mod;
  if( y%2 ){
    return (((temp*temp)%mod)*x%mod);
  }
  return (temp*temp)%mod;
}

void solve(){
  ll n,i,j,k;cin>>n;string s; cin>>s;
  for(i=0;i<2*n-1;i+=2)cout<<s[i];
  cout<<"\n";
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