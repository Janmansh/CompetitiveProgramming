#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    long double x,ans=0,pi=3.14159265359;
    setprecision(25);
    x=((2*n-2)*180.0)/(2*n);
    //cout<<x<<endl;
    for(i=1;i<n/2;i++){
      ans=ans+sin((i*x-(90+(i-1)*180))*pi/180.0);
    }
    ans=ans*2.0;
    ans=ans+1;
    cout<<setprecision(25)<<ans<<endl;
  }
}