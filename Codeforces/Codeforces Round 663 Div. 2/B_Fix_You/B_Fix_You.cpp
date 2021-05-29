#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
  ll i,j=0,n,m;
  cin>>n>>m;
  string a[n];
  ll ans=0;
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n-1;i++){
    if(a[i][m-1]=='R'){ans++;a[i][m-1]='D';}
  }
  for(i=0;i<m-1;i++){
    if(a[n-1][i]=='D'){ans++;a[n-1][i]='R';}
  }cout<<ans;
  cout<<"\n";
  
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