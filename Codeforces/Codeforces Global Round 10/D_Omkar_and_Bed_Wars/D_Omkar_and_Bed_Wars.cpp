#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back

void solve(){
  ll n,i,j,k=0;
  cin>>n;ll a[n],b[n],d[n];string s;
  //for(i=0;i<n;i++)cin>>a[i];
  cin>>s;
  j=1;
  string s1;
  for(i=0;i<2*n;i++){
    s1.pb(s[i%n]);
  }
  //cout<<s1;
  int f=0;
  for(i=1;i<n;i++){
    if(s[i]!=s[i-1]){f=1;break;}
  }
  if(f==0){
    if(n%3==0)cout<<n/3<<"\n";
    else cout<<n/3 + 1<<"\n";
    return;
  }
  for(i=0;i<2*n;i++){
    if(s1[i]!=s1[i+n-1])break;
  }
  ll t=1;k=0;
  for(j=i+1;j<i+n;j++){
    if(s1[j]!=s1[j-1]){k+=(t/3);t=1;}
    else t++;
  }
  k+=(t/3);
  cout<<k<<"\n";
  return;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
