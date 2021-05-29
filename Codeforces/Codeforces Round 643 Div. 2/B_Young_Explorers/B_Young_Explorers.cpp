#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i,j;
  cin>>t;
  while(t--){
    cin>>n;
    j=0;
    long long a[n],ans=0,temp;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++){
      j++;
      if(a[i]==j){
        ans++;
        j=0;
        continue;
      }
    }
    cout<<ans<<endl;
  }
}