#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define m 1000000007

ll power(ll x,ll y){
  if(y==0)return 1;
  ll temp=power(x,y/2);
  if(y%2){
    return (((temp*temp)%m)*x)%m;
  }
  return (temp*temp)%m;
}


void solve(){
  ll n,i,j,r,g,b,w;
  cin>>r>>g>>b>>w;
  if((r%2==0&&g%2==0&&w%2==0)||(r%2==0&&g%2==0&&b%2==0)||(r%2==0&&w%2==0&&b%2==0)||(w%2==0&&g%2==0&&b%2==0)){
    cout<<"YES\n";return;
  }
  r--;w+=3;g--;b--;
  if(((r%2==0&&g%2==0&&w%2==0)||(r%2==0&&g%2==0&&b%2==0)||(r%2==0&&w%2==0&&b%2==0)||(w%2==0&&g%2==0&&b%2==0))&&(r>=0&&g>=0&&b>=0&&w>=0)){
    cout<<"YES\n";return;
  }
  cout<<"NO\n";return;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t;
  cin>>t;
  //t=1;
  while(t--){
    solve();
  }
}