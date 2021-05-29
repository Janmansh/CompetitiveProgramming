#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int long long
#define mp make_pair


void solve(){
  ll n,i,j,k,x1,y1,z1,x2,y2,z2;cin>>x1>>y1>>z1>>x2>>y2>>z2;
  if(y2>=z1){
    ll ans=0;
    ans+=(z1*2);
    y2-=z1;z1=0;
    if(x1>=z2){
      cout<<ans<<"\n";return;
    }
    else{
      z2-=x1;x1=0;
      ans-=(z2*2);
      cout<<ans<<"\n";return;
    }
  }
  else{
    ll ans=0;
    ans+=(y2*2);
    z1-=y2;y2=0;
    if((z1+x1)>=z2){
      cout<<ans<<"\n";return;
    }
    else{
      z2-=(z1+x1);
      ans-=(z2*2);
      cout<<ans<<"\n";return;
    }
  }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t;
  cin>>t;
  //t=1;
  while(t--){
    solve();
  }
}