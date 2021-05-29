#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t,a,b,c,n,i,j,m;
  cin>>t;
  while(t--){
    cin>>n;
    long long a[2*n],c[n],c1[n];
    vector<long long>v;
    for(i=0;i<n;i++)c[i]=0,c1[i]=0;
    for(i=0;i<2*n;i++){cin>>a[i];c[a[i]-1]++;}
    for(i=0;i<2*n;i++){
      if(c1[a[i]-1]==(c[a[i]-1]/2))continue;
      c1[a[i]-1]++;
      v.push_back(a[i]);
    }
    for(i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<"\n";
  }
}