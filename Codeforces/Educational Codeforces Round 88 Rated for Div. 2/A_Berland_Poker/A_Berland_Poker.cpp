#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t;
  cin>>t;
  while(t--){
  long long n,m,k,ans;
  cin>>n>>m>>k;
  if(n/k>=m){
    cout<<m<<endl;
    continue;
  }
  if(m==0||m==n||n/k==1){
    cout<<"0"<<endl;
    continue;
  }
  if(n/k<m){
    cout<<n/k-ceil((m-n/k)/(k-1.0))<<endl;
  }
}
}