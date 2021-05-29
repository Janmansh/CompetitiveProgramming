#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k,t,i,j;
  cin>>t;
  while(t--){
  cin>>n;
  if(n==1){cout<<"0"<<endl;continue;}
  k=0;
  for(i=n;i>=0;i-=2){
    k+=(i/2*4*(i-1));
  }
  cout<<k<<endl;
  }
}