#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,n,i,a,b,j;
  cin>>t;
  while(t--){
    cin>>n>>a>>b;
    char c[n];
    i=0;
    for(j=0;j<n;j++){
      c[j]=97+i;
      i++;
      if(i==b){
        i=0;
      }
    }
    for(i=0;i<n;i++){
      cout<<c[i];
    }
    cout<<endl;
  }
}