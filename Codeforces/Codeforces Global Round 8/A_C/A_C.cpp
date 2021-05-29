#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,a,b,n,i;
  cin>>t;
  while(t--){
    cin>>a>>b>>n;
    long long x=min(a,b),y=max(a,b),c=0;
    while(x<=n&&y<=n){
      if(c%2){y+=x;c++;}
      else{x+=y;c++;}
    }
    cout<<c<<"\n";
  }
}