#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i,j;
  cin>>t;
  while(t--){
    cin>>n;
    if(n<4){cout<<"-1\n";continue;}
    if(n==4){cout<<"3 1 4 2\n";continue;}
    long long k=n-1;
    while(k>0){
      cout<<k<<" ";
      k-=2;
    }
    if(k==0){
      k+=2;
      cout<<k+3<<" "<<k-1<<" "<<k+1<<" ";
      k+=5;
      while(k<=n){
        cout<<k<<" ";
        k+=2;
      }
    }
    else{
      k+=2;
      cout<<k+3<<" "<<k+1<<" ";
      k+=5;
      while(k<=n){
        cout<<k<<" ";
        k+=2;
      }
    }
    cout<<"\n";
  }
}