#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
  ll a,b,c,d,i,ans=0;
  cin>>a>>b>>c>>d;
  cout<<(d-b)*(c-a)+1<<"\n";
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