#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,a1,k,i,j;
  cin>>t;
  while(t--){
    cin>>a1>>k;
    long long ans=0,min,max;
    long long a[10]={0},l;
    k--;
    while(k){
      l=a1;
      for(i=0;i<10;i++){
        a[i]=0;
      }
      while(l){
        a[l%10]++;
        l/=10;
      }
      for(j=0;j<10;j++){
        if(a[j]){
          min=j;
          break;
        }
      }
      for(j=9;j>=0;j--){
        if(a[j]){
          max=j;
          break;
        }
      }
      if(min==0){
        break;
      }
      a1=a1+min*max;
      k--;
    }
    ans=a1;
    cout<<ans<<endl;
  }
}