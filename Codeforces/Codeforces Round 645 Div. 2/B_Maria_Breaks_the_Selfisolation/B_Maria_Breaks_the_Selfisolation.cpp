#include<bits/stdc++.h>
using namespace std;
int main(){
  long t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    long a[n],ans=0,p=n+1;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(a[n-1]<=n){
      cout<<n+1<<endl;
      continue;
    }
    for(i=n-1;i>=0;i--){
      if(a[i]>i+1){
        p--;
      }
      else{
        break;
      }
    }
    cout<<p<<endl;
  }
}