#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
  ll n,m,i,j,d,w,sum=0;
  cin>>n;
  if(n%4==0){
    w=(n/4);
    for(i=0;i<n-w;i++){
      cout<<"9";
    }
    for(i=0;i<w;i++)cout<<"8";
    cout<<"\n";
  }
  else{
    w=(n/4)+1;
    for(i=0;i<n-w;i++){
      cout<<"9";
    }
    for(i=0;i<w;i++)cout<<"8";
    cout<<"\n";
  }
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