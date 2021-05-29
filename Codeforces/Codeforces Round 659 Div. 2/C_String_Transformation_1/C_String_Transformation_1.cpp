#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  ll n,m,i,j,f=0,k,l,ans=0;
  cin>>n;
  string a,b;
  cin>>a;cin>>b;
  for(i=0;i<a.length();i++){
    if(a[i]!=b[i]){
      if(a[i]>=b[i]){
        cout<<"-1\n";return;
      }
    }
  }
  for(i=0;i<26;i++){
    vector<ll>v;
    char min='z';
    for(j=0;j<a.length();j++){
      if(a[j]==('a'+i)){
        if(b[j]!=a[j]){
          if(b[j]<min)min=b[j];
          v.push_back(j);
        }
      }
    }
    if(v.size()!=0)ans++;
    for(j=0;j<v.size();j++){
      a[v[j]]=min;
    }
    v.clear();
  }
  cout<<ans<<"\n";
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