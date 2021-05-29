#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
  ll n,m,i,j,d,w,sum=0;
  cin>>n;
  if(n<=30){
    cout<<"NO\n";return;
  }
  if(n==36){
    cout<<"YES\n5 6 10 15\n";return;
  }
  if(n==40){
    cout<<"YES\n6 14 15 5\n";return;
  }
  if(n==44){
    cout<<"YES\n6 10 15 13\n";return;
  }
  cout<<"YES\n6 10 14 "<<n-30<<"\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t;
  cin>>t;
  //t=1;
  while(t--){
    solve();
  }
}