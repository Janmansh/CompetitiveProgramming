#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back

void solve(){
  ll n,i,j,a1,a2=-1,a3;
  cin>>n;ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  a1=1;a3=n;
  for(i=1;i<n-1;i++)if(a[0]+a[i]<=a[n-1]){
    a2=i+1;break;
  }
  if(a2==-1)cout<<a2<<"\n";
  else cout<<a1<<" "<<a2<<" "<<a3<<"\n";
  return;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
