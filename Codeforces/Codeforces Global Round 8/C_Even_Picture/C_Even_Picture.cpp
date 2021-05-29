#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,i,j;
  cin>>n;
  cout<<(n+1)*3+1<<"\n";
  cout<<"0 0\n0 1\n1 0\n";
  for(i=1;i<=n;i++){
    cout<<i<<" "<<i<<"\n";
    cout<<i<<" "<<i+1<<"\n";
    cout<<i+1<<" "<<i<<"\n";
  }
  cout<<n+1<<" "<<n+1<<"\n";
}