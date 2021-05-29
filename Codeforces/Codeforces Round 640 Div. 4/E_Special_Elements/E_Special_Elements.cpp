#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t,n,i,j;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    //sort(a,a+n);
    int ans=0;
    for(i=0;i<n;i++){
      int sum=0,k=0;
      for(j=0;j<n;j++){
        sum+=a[j];
        if(sum>a[i]&&j-k>1){sum-=a[k];k++;sum-=a[j];j--;}
        else if(sum==a[i]&&j-k>=1){ans++;break;}
      }
    }
    cout<<ans<<"\n";
  }
}