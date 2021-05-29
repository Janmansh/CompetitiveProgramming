#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,k,t,i,j;
  cin>>t;
  while(t--){
  cin>>n>>k;
  long long a[n],b[n],ans=0,c=0;
  for(i=0;i<n;i++) cin>>a[i];
  for(j=0;j<n;j++) cin>>b[j];
  sort(a,a+n);
  sort(b,b+n);
  j=0;
  for(i=0;i<n;i++){
    if(c==k)break;
    if(a[i]<b[n-j-1]){
      a[i]=b[n-j-1];
      c++;j++;
    }
    else{
      break;
    }
  }
  for(i=0;i<n;i++)ans+=a[i];
  cout<<ans<<endl;
  }
}