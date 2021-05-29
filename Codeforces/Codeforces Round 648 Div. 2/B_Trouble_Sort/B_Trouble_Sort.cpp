#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,m,i,j;
  cin>>t;
  while(t--){
    cin>>n;
    long long a[n],b[n],f=1,o=0,z=0;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++){cin>>b[i];
      if(b[i]==0)z++;
      else o++;
    }
    for(i=0;i<n;i++){
      for(j=i;j<n;j++){
        if(a[j]<a[i])f=0;
      }
    }
    if(f){cout<<"Yes\n";continue;}
    f=1;
    if(o==0||z==0)f=0;
    if(f)cout<<"Yes\n";
    else cout<<"No\n";
  }
}