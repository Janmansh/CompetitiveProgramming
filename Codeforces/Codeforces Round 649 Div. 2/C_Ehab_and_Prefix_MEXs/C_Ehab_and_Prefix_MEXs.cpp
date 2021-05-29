#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,i;
    cin>>n;
    ll a[n],b[n],c[100001]={0},k=0,m=n;
    for(i=0;i<n;i++){
      cin>>a[i];
      c[a[i]]++;
    }
    for(i=0;i<n;i++){
      if(c[i]==0){
        m=i;
        break;
      }
    }
    for(i=0;i<n;i++){
      if(i==0||a[i]==a[i-1]){
        k=m;
        b[i]=k;
        m++;
        while(c[m]!=0){
          m++;
        }
      }
      else{
        b[i]=a[i-1];
      }
    }
    for(i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<"\n";
}