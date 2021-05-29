#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,a,b,c,d,i;
  cin>>t;
  while(t--){
    cin>>a>>b>>c>>d;
    long long ans=b;
    if(b>=a){
      cout<<b<<endl;
      continue;
    }
    if(b<a&&d>=c){
      cout<<"-1"<<endl;
      continue;
    }
    long long x;
    if((a-b)%(c-d)==0){
      x=(a-b)/(c-d);
    }
    else{
      x=(a-b)/(c-d)+1;
    }
    ans=ans+x*c;
    cout<<ans<<endl;
  }
}