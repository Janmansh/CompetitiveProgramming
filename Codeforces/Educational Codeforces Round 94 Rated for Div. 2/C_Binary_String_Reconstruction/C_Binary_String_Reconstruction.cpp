#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int long long
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
  ll n,i,j,x;string s;cin>>s;cin>>x;
  n=s.length();
  string w;
  for(i=0;i<n;i++)w.pb('1');
  for(i=0;i<n;i++){
    if(s[i]=='0'){
      if(i-x>=0)
        w[i-x]='0';
      if(i+x<n)
        w[i+x]='0';
    } 
  }
  for(i=0;i<n;i++){
    if(s[i]=='0')continue;
    else{
      j=0;
      if(i+x<n&&w[i+x]=='1')
        j=1;
      if(i-x>=0&&w[i-x]=='1')
        j=1;
        
      if(j==0){
        cout<<"-1\n";return;
      }
    }
  }
  cout<<w<<"\n";
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