#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int long long
#define mp make_pair


void solve(){
  ll n,i,j,k; cin>>n;
  ll a[n],b[n];
  //vector<pair<ll,ll>>v;
  for(i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
  sort(b,b+n);
  if(is_sorted(a,a+n)){
    cout<<"YES\n";return;
  }
  // ll mn=10000000000;
  // for(i=0;i<n;i++)if(a[i]<mn){j=i;mn=a[i];}
  // if(__gcd(a[0],a[j])==a[j]){
  //   ll temp=a[0];
  //   a[0]=a[j];a[j]=temp;
  // }
  // else{
  //   cout<<"NO\n";return;
  // }
  //ll mn=(*min_element(a,a+n));
  for(i=0;i<n;i++){
    if(a[i]!=b[i]&&__gcd(a[i],b[0])!=b[0]){
      cout<<"NO\n";return;
    }
  }
  cout<<"YES\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t;
  cin>>t;
  //t=1;
  while(t--){
    solve();
  }
}