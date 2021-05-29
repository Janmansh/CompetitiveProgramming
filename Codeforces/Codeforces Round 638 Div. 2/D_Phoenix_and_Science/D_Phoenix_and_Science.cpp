#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){  
  ll n,i;
  cin>>n;
  vector<ll>inc; 
  for(i=1;i<=n;i*=2){
    inc.push_back(i);
    n-=i;
  }
  if(n>0){
    inc.push_back(n);
    sort(inc.begin(),inc.end());
  }
  cout<<inc.size()-1<<"\n";
  for (i=1;i<inc.size();i++)
    cout<<inc[i]-inc[i-1]<<" ";
  cout<<"\n";
}

int main(){
  ll t; cin>>t;
  while (t--)
    solve();
}