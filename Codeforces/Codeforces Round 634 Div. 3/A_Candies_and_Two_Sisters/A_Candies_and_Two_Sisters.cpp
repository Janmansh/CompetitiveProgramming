#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    if(n%2){
      cout<<n/2<<endl;
    }
    else{
      cout<<n/2-1<<endl;
    }
  }
}