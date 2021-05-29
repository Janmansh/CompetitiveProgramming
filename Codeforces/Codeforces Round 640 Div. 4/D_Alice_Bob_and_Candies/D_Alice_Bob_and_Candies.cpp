#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i,j;
  cin>>t;
  while(t--){
    cin>>n;
    long long a[n],ans=0;
    for(i=0;i<n;i++)cin>>a[i];
    long long snow=0,sprev=0,alice=0,bob=0,ll=0,ul=n-1,f=0;
    for(i=ll;i<=ul;i++){
      if(f==0){ans++;f=1;}
      alice+=a[i];
      ll++;
      snow+=a[i];
      if(snow>sprev){
      f=0;
      sprev=snow;
      snow=0;
      for(j=ul;j>=ll;j--){
        if(f==0){ans++;f=1;}
        bob+=a[j];
        ul--;
        snow+=a[j];
        if(snow>sprev){
          sprev=snow;
          snow=0;
          f=0;
          break;
        }
      }
      }
    }
    cout<<ans<<" "<<alice<<" "<<bob<<"\n";
  }
}