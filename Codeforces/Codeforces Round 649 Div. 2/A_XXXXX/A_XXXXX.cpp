#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,x,i;
  cin>>t;
  while(t--){
    cin>>n>>x;
    long long a[n],sum=0,b[n],k=0;
    for(i=0;i<n;i++){
      cin>>a[i];
      sum+=a[i];
      if(a[i]%x!=0)b[k++]=i;
    }
    if(sum%x!=0){
      cout<<n<<"\n";continue;
    }
    else{
      if(k==n)cout<<n-1<<"\n";
      else if(k==0)cout<<"-1\n";
      else {
        cout<<max(n-1-b[0],b[k-1])<<"\n";
      }
    }
  }
}