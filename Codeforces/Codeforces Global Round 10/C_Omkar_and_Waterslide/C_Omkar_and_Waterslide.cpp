#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back

void solve(){
  ll n,i,j,k=0;
  cin>>n;ll a[n],b[n],d[n];
  for(i=0;i<n;i++)cin>>a[i];
  for(i=1;i<n;i++){
    if(a[i]<a[i-1])k+=a[i-1]-a[i];
  }
  cout<<k<<"\n";
  return;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
