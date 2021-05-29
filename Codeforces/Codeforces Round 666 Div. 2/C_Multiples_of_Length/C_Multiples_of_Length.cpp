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
  ll n,i,j;cin>>n;ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  if(n==1){
    cout<<"1 1\n";
    cout<<-1*a[0]<<"\n";
    cout<<"1 1\n0\n1 1\n0\n";return;
  }
  cout<<"1 "<<n<<"\n0 ";
  for(i=1;i<n;i++){
    cout<<((n)*(n-1-(a[i]%(n-1))))<<" ";
    a[i]+=((n)*(n-1-(a[i]%(n-1))));
  }
  cout<<"\n1 1\n";
  cout<<-1*a[0]<<"\n";
  cout<<"2 "<<n<<"\n";
  for(i=1;i<n;i++)cout<<-1*a[i]<<" ";
  cout<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  while (t--){
    solve();
  }
  return 0;
}