#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back

void solve(){
  ll n,i,j,a1,a2,a3;
  string s;
  cin>>s;
  a1=0;vector<ll>a;
  for(i=0;i<s.length();i++){
    if(s[i]=='1')a1++;
    else{if(a1!=0)a.pb(a1); a1=0;}
  }
  if(a1!=0)a.pb(a1);
  sort(a.begin(),a.end(),greater<ll>());
  a2=0;
  for(i=0;i<a.size();i+=2)a2+=a[i];
  cout<<a2<<"\n";
  return;
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
