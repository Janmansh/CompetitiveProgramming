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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}



void solve(){
  ll n,i,j; cin>>n; ll a[n];vector<int>b; for(i=0;i<n;i++)cin>>a[i];
  i=0,j=n-1;
  ll f[n]={0};
  while(i<j){
    b.pb(a[i]);
    f[i]=1;
    i++;
    b.pb(a[j]);
    f[j]=1;
    j--;
  }
  for(i=0;i<n;i++){
    if(f[i]==0){b.pb(a[i]);break;}
  }
  for(i=0;i<n;i++)cout<<b[i]<<" ";
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