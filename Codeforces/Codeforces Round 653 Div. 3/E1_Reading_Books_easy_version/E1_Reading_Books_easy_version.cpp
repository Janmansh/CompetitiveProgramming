#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n,i,j,x,k,y;
  cin>>n>>k;
  long long t[n],a[n],b[n],a1=0,b1=0;
  vector<long long> ta,tb,tba;
  for(i=0;i<n;i++){
    cin>>t[i]>>a[i]>>b[i];
    if(a[i])a1++;
    if(b[i])b1++;
  }
  if(a1<k||b1<k){
    cout<<"-1\n"; return 0;
  }
  for(i=0;i<n;i++){
    if(a[i]==1&&b[i]==1){
      tba.push_back(t[i]);
    }
    else if(a[i]==1&&b[i]==0)ta.push_back(t[i]);
    else if(b[i]==1&&a[i]==0)tb.push_back(t[i]);
  }
  sort(ta.begin(),ta.end());sort(tb.begin(),tb.end());sort(tba.begin(),tba.end());
    x=min(ta.size(),tb.size());
    if(x>k)x=k;
    long long ans=0,sum=10000000000000;
    for(i=0;i<=x;i++){
      ans=0;
      for(j=0;j<x-i;j++){
        ans+=ta[j];ans+=tb[j];
      }
      for(j=0;j<k-x+i;j++){
        ans+=tba[j];
      }
      sum=min(ans,sum);
      if(k-x+i==tba.size())break;
    }
    cout<<sum<<"\n";
    return 0;
}