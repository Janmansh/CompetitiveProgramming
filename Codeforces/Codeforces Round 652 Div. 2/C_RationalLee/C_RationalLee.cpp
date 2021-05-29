#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,k,i,j;
  cin>>t;
  while(t--){
    cin>>n>>k;
    long long a[n];
    for(i=0;i<n;i++)cin>>a[i];
    long long b[k];
    for(i=0;i<k;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+k);
    vector<long long>r[k];
    long long back=1;
    long long s=0,sum=0;
    for(i=0;i<k;i++){
      b[i]--;
      sum+=a[n-back];
      //sum+=a[n-back];
      //if(b[i]==1){
        //back++;
        //sum+=a[n-back];
      //}
      //else if(b[i]>0){
        //sum+=a[s];
        //s+=b[i];
      //}
      //else if(b[i]==0){
        //sum+=a[n-back];
      //}
      if(b[i]==0)sum+=a[n-back];
      back++;
    }
    s=0;
    for(i=k-1;i>=0;i--){
      if(b[i]==0)continue;
      sum+=a[s];
      s+=b[i];
    }
    cout<<sum<<"\n";
  }
}