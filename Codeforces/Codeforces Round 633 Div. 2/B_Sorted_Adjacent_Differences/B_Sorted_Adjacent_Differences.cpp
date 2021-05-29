#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,n,i,j;
  cin>>t;
  while(t--){
    cin>>n;
    ll a[n],b[n];
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    ll l=0;
    for(i=0;(i+n/2)<n;i++){
      b[l]=a[n/2+i];
      l+=2;
    }
    l=1;
    for(i=1;(n/2-i)>=0;i++){
      b[l]=a[n/2-i];
      l+=2;
    }
    for(i=0;i<n;i++){
      cout<<b[i]<<" ";
    }
    cout<<endl;
  }
}