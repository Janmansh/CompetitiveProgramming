#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back

void solve(){
  ll n,i,j,k;
  cin>>n>>k;ll a[n],b[n],d[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll c=*max_element(a, a+n);
  for(i=0;i<n;i++)b[i]=c-a[i];
  c=*max_element(b, b+n);
  for(i=0;i<n;i++)d[i]=c-b[i];
  if(k%2){
    for(i=0;i<n;i++)cout<<b[i]<<" ";
  }
  else for(i=0;i<n;i++)cout<<d[i]<<" ";
  cout<<"\n";
  return;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
