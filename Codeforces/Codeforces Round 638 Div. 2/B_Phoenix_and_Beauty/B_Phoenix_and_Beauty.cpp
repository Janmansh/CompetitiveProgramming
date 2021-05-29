#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
  ll n,k,i,j,ans=0;
  cin>>n>>k;
  ll c[n];
  vector<ll>a,b;
  for(i=0;i<n;i++){cin>>j;a.pb(j);c[i]=0;}
  for(i=0;i<n;i++){
    if(c[a[i]-1]==0){c[a[i]-1]=1;b.pb(a[i]);}
  }
  if(b.size()>k){
    cout<<"-1\n";return;
  }
  if(b.size()<k){
    j=b.size();
    for(i=0;i<k-j;i++){
      b.pb(b.back());
    }
  }
  cout<<a.size()*b.size()<<"\n";
  for(i=0;i<n;i++){
    for(j=0;j<b.size();j++){
      cout<<b[j]<<" ";
    }
  }
  cout<<"\n";
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