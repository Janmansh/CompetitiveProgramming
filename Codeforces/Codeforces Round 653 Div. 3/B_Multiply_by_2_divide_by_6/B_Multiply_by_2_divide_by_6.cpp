#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i,j,x,y;
  cin>>t;
  while(t--){
    cin>>n;
    long long ans=0,c=0;
    if(n==1){
      cout<<"0\n";
      continue;
    }
    while(n%6==0){
      ans++;
      n/=6;
    }
    if(n==1){
      cout<<ans<<"\n";
      continue;
    }
    while(n%3==0){
      c++;
      n/=3;
    }
    if(n==1){
      ans+=(2*c);
      cout<<ans<<"\n";
    }
    else{
      cout<<"-1\n";
      continue;
    }
  }
}