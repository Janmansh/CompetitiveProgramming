#include<bits/stdc++.h>
using namespace std;

long long mostFrequent(long long arr[], long long n) 
{
    unordered_map<long long, long long> hash; 
    long long i;
    for (i = 0; i < n; i++) 
        hash[arr[i]]++; 
    long long max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return res; 
}

int main(){
  long long t,n,m,i,j;
  cin>>n;
  long long a[n],b[n];
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n;i++)cin>>b[i];
  long long c[n+1],d[n+1];
  for(i=0;i<n;i++){
    c[a[i]]=i;d[b[i]]=i;
  }
  long long dif[n];
  for(i=1;i<=n;i++){
    dif[i-1]=c[i]-d[i];
    if(dif[i-1]<0)dif[i-1]+=n;
  }
  long long x=mostFrequent(dif, n),ans=0;
  for(i=0;i<n;i++){
    if(dif[i]==x){
      ans++;
    }
  }
  cout<<ans<<"\n";
}