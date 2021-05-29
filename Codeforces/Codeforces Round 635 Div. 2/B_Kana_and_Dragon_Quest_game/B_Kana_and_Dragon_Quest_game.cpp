#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,x,n,m;
  cin>>t;
  while(t--){
    cin>>x>>n>>m;;
    while(x>20&&n){
      x=x/2+10;
      n--;
    }
    if(x-m*10<=0){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}