#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i,j,s;
  cin>>n>>s;
  if(s-n+1>n){
    cout<<"YES"<<endl;
    for(i=0;i<n-1;i++){
      cout<<1<<" ";
    }
    cout<<s-n+1<<endl;
    cout<<n<<endl;
    return 0;
  }
  cout<<"NO"<<endl;
}