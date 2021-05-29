#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    int ans=0,i=0,j;
    int k=n,x[n];
    while(k){
      x[i]=k%10;
      i++;
      k/=10;
    }
    for(j=i-1;j>=0;j--){
      if(x[j]!=0){
        ans++;
      }
    }
    cout<<ans<<endl;
    for(j=i-1;j>=0;j--){
      if(x[j]!=0){
        cout<<x[j]*pow(10,j)<<" ";
      }
    }
    cout<<endl;
  }
}