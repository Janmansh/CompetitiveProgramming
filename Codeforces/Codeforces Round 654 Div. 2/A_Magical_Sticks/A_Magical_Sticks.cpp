#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    if(n%2){
      cout<<n/2 + 1<<"\n";
    }
    else{
      cout<<n/2<<"\n";
    }
  }
}