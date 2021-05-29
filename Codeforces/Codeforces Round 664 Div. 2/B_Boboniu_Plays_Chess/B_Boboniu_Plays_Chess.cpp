#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define m1 1000000007

ll power(ll x,ll y){
  if(y==0)return 1;
  ll temp=power(x,y/2);
  if(y%2){
    return (((temp*temp)%m1)*x)%m1;
  }
  return (temp*temp)%m1;
}


void solve(){
  ll n,m,i,j,x,y;
  cin>>n>>m>>x>>y;
  vector<ll>xa,ya;
  xa.pb(x);ya.pb(y);
  ll tl=y;
  while(tl>1){
    xa.pb(x);ya.pb(--tl);
  }
  xa.pb(x);ya.pb(y+1);tl=y+1;
  while(tl<m){
    xa.pb(x);ya.pb(++tl);
  }
  for(i=m;i>=1;i--){
    for(j=1;j<=n;j++){
      if(j==x)continue;
      xa.pb(j);ya.pb(i);
    }
    i--;
    if(i<1)break;
    for(j=n;j>=1;j--){
      if(j==x)continue;
      xa.pb(j);ya.pb(i);
    }
  }
  for(i=0;i<xa.size();i++){
    cout<<xa[i]<<" "<<ya[i]<<"\n";
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t;
  //cin>>t;
  t=1;
  while(t--){
    solve();
  }
}