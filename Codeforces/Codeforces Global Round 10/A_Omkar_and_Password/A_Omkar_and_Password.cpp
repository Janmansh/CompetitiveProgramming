#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back

void solve(){
  ll n,i,j;
  cin>>n;ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll c=1;
  for(i=1;i<n;i++)if(a[i]!=a[i-1]){c++;break;}
  if(c==1)cout<<n<<"\n";
  else cout<<"1\n";
  return;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
