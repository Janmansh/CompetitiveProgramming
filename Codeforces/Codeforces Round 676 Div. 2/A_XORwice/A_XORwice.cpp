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
  ll a,b,i,j; cin>>a>>b;
  ll t1=a,t2=b;
  ll ab[32]={0},bb[32]={0};
  i=0;
  while(a){
    ab[i]=a%2;
    a/=2;i++;
  }
  i=0;
  while(b){
    bb[i]=b%2;
    b/=2;i++;
  }
  ll ans[32];
  for(i=0;i<32;i++){
    if(ab[i]==bb[i])ans[i]=ab[i];
    else ans[i]=0;
  }
  ll an=0;
  for(i=0;i<32;i++){
    an+=(power(2,i)*ans[i]);
  }
  cout<<(an^t1)+(an^t2)<<"\n";
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