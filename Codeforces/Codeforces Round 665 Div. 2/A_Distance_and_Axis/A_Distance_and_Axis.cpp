#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int long long
#define mp make_pair


void solve(){
  ll n,i,j,k;cin>>n>>k;
  if(k==0&&n%2==1){
    cout<<"1\n";return;
  }
  if(k==0&&n%2==0){
    cout<<"0\n";return;
  }
  if(k>=n){
    cout<<k-n<<"\n";return;
  }
  if(k%2==n%2){
    cout<<"0\n";return;
  }
  cout<<"1\n";
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