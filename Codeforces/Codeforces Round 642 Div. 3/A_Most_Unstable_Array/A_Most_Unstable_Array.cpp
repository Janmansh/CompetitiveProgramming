#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,m,t;
  cin>>t;
  while(t--){
  cin>>n>>m;
  if(n==1){cout<<"0"<<endl;continue;}
  if(n==2){cout<<m<<endl;continue;}
  cout<<2*m<<endl;
  }
}