#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t,a,b,c,n,i,j,m;
  cin>>t;
  while(t--){
    cin>>n;
    long long a[n],c[n],c1[n],ans=0;
    vector<long long>v;
    //for(i=0;i<n;i++)c[i]=0,c1[i]=0;
    for(i=0;i<n;i++){cin>>a[i];}
    for (i=n-1;i>=1;i--){
            if (a[i]>a[i-1])
                break;
    }
    for (;i>=1;i--){
      if (a[i]<a[i-1])
      break;
    }
    cout<<i<<"\n";
  }
}