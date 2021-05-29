#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,n,x,m,i;
  cin>>t;
  while(t--){
    cin>>n>>x>>m;
    ll ans=1,ul=0,low=1000000000,f=0;
    ll l,r;
    while(m--){
      cin>>l>>r;
      if(x>=l&&x<=r){
        f=1;
        ul=r;
        low=l;
        break;
      }
    }
    if(f){
    while(m--){
      cin>>l>>r;
      if(r<low||l>ul){continue;}
      else{
        if(r>ul)ul=r;
        if(l<low)low=l;
      }
    }
    ans=ul-low+1;
    }
    cout<<ans<<"\n";
  }
}