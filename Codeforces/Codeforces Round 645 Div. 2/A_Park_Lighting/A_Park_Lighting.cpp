#include<bits/stdc++.h>
using namespace std;
int main(){
  long t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    if(n%2==0||m%2==0){
      if(n%2==0){
        cout<<n/2*m<<endl;
        continue;
      }
      cout<<m/2*n<<endl;
      continue;
    }
    cout<<(n-1)/2*m + (m-1)/2 + 1<<endl;
  }
}