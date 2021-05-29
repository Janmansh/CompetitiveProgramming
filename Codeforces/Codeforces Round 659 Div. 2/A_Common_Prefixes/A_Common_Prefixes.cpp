#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  ll n,m,i,j,f=0;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  string s[n+1];
  for(i=0;i<=50;i++)s[0].push_back('a');
  for(i=0;i<n;i++){
    for(j=0;j<a[i];j++){
      s[i+1].push_back(s[i][j]);}
      for(j=a[i];j<=50;j++){
        if(s[i][j]=='a')s[i+1].push_back('b');
        else s[i+1].push_back('a');
      }
  }
  for(i=0;i<n+1;i++)cout<<s[i]<<"\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t;
  cin>>t;
  while(t--){
    solve();
  }
}