#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll i,j,n,x,t;
  cin>>t;
  while(t--){
    cin>>n>>x;
    ll a[n];
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    ll o=0,e=0;
    for(i=0;i<n;i++){
      if(a[i]%2)o++;
      else e++;
    }
    if(o==0){
      cout<<"No"<<"\n";
      continue;
    }
    if(x==n){
      if(x%2){
        if(e%2){
          cout<<"No"<<"\n";
          continue;
        }
        else{
          cout<<"Yes\n";
          continue;
        }
      }
      else{
        if(e%2){
          cout<<"Yes"<<"\n";
          continue;
        }
        else{
          cout<<"No\n";
          continue;
        }
      }
    }
    if(x%2==1){
      cout<<"Yes"<<"\n";
      continue;
    }
    if(x%2==0){
      if(e==0){
        cout<<"No"<<"\n";
        continue;
      }
      else{
        cout<<"Yes\n";
        continue;
      }
    }
    cout<<"Yes\n";
  }
}