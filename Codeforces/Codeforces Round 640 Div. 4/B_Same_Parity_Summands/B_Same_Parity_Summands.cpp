#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    if(k>n){
      cout<<"NO"<<endl;
      continue;
    }
    if(k==n){
      cout<<"YES"<<endl;
      for(i=0;i<k;i++){
        cout<<"1 ";
      }
      cout<<endl;
      continue;
    }
    if((n-k+1)%2==1){
      cout<<"YES"<<endl;
      cout<<n-k+1<<" ";
      for(i=0;i<k-1;i++){
        cout<<"1 ";
      }
      cout<<endl;
      continue;
    }
    if((n-(k-1)*2)%2==0&&(n-(k-1)*2)>0){
      cout<<"YES"<<endl;
      cout<<n-(k-1)*2<<" ";
      for(i=0;i<k-1;i++){
        cout<<"2 ";
      }
      cout<<endl;
      continue;
    }
    cout<<"NO"<<endl;
  }
}