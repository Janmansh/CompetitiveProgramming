#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){  
  ll n,k1,k2,i,j,sum=0,x,s1=0;
  cin>>n;
  ll a[2*n],b[2*n],c[2*n],d[2*n];
  for(i=0;i<n;i++){
    cin>>a[i]>>b[i];
    a[n+i]=a[i];
    b[n+i]=b[i];
  }
  for(i=0;i<n;i++){c[i]=a[i],d[i]=b[i];c[n+i]=c[i];d[n+i]=d[i];}
  x=distance(a,min_element(a,a+n));
  //cout<<x;
  for(i=x;i<2*n+x-n;i++){
    if(a[i]>0)sum+=a[i];
    a[i+1]-=b[i];
  }
  x=distance(d,min_element(d,d+n));
  x++;
  for(i=x;i<2*n+x-n;i++){
    if(c[i]>0)s1+=c[i];
    c[i+1]-=d[i];
  }
  cout<<min(sum,s1)<<"\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll t; cin>>t;
  while (t--)
    solve();
}