#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i,j,x,y;
  cin>>t;
  while(t--){
    cin>>x>>y>>n;
    long long f=0,k;
    k=n/x;
    k=(k*x);
    if(k+y<=n){
      k=k+y;
    }
    else{
      k-=x;
      k+=y;
    }
    cout<<k<<"\n";
  }
}