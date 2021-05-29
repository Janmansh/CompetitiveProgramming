#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,i,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    string s;
    cin>>s;
    long long c=0,o=0,d[n];
    long long j=0;
    for(i=0;i<s.length();i++){
      if(s[i]=='1')d[j++]=i;
    }
    if(j==0){
        long long ans=0;
        for(i=0;i<n;i+=(k+1)){
          ans++;
        }
        cout<<ans<<"\n";
        continue;
    }
    for(i=1;i<j;i++){
      if((d[i]-d[i-1]-1-k)>0)
      c+=(((d[i]-d[i-1]-1)-k)/(k+1));
    }
    c+=(d[0])/(k+1);
    c+=(n-1-d[j-1])/(k+1);
    cout<<c<<"\n";
  }
}