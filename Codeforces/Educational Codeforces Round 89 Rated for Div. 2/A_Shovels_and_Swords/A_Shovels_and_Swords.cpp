#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,a,b,i;
  cin>>t;
  while(t--){
    cin>>a>>b;
    ll ans=0;
    ll x=max(a,b),y=min(a,b);
    if(x/2>=y){ans+=y;}
    else{
      ans+=(x+y)/3;
    }
    cout<<ans<<"\n";
  }
}