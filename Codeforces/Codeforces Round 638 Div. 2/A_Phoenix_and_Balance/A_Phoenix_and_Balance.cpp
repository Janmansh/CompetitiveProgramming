#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    ll f=0,s=0;
    for(i=1;i<n/2;i++){
      f+=pow(2,i);
    }
    for(i=n/2;i<n;i++){
      f-=pow(2,i);
    }
    f+=pow(2,n);
    cout<<abs(f)<<endl;
  }
}