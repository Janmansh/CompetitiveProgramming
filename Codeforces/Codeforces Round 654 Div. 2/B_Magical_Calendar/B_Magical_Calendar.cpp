#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i,r,j;
  cin>>t;
  while(t--){
    cin>>n>>r;
    if(r==1){
      cout<<"1\n";
      continue;
    }
    if(r>=n){
      cout<<(n)*(n-1)/2 + 1<<"\n";
    }
    else{
      cout<<(r)*(r+1)/2<<"\n";
    }
  }
}