#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];

ll powermod(ll x,ll y){
  if(y==0) return 1;
  ll temp = powermod( x,y/2 )%mod;
  if( y%2 ){
    return (((temp*temp)%mod)*x%mod);
  }
  return (temp*temp)%mod;
}

ll power(ll x,ll y){
  if(y==0) return 1;
  ll temp = power( x,y/2 );
  if( y%2 ){
    return (((temp*temp))*x);
  }
  return (temp*temp);
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

ll inv(ll a, ll p){
	return powermod(a,mod-2);
}
 
ll nCr(ll n, ll r, ll p){
	if(r > n) return 0;
	ll t1 = fact[n];
	ll t2 = inv(fact[r],p);
	ll t3 = inv(fact[n-r],p);
 
	return (((t1*t2)%p)*t3)%p;
}
void solve() {
  ll i,j,n;
  string s;
  cin>>s;
  n=s.length();
  int f=1;
  for(i=0;i<n;i++){
    if(s[i]!='a')f=0;
  }
  if(f){
    cout<<"NO\n";return;
  }
  cout<<"YES\n";
  f=0;
  string ans;
  for(i=0;i<n;i++){
    if(f==0&&s[i]=='a'){
      ans.pb('a');
      ans.pb(s[i]);
      f=1;
    }
    else{
      ans.pb(s[i]);
    }
  }
  if(f==0){
    ans.pb('a');
  }
  n++;
  f=0;
  for(i=0;i<n/2;i++){
    if(ans[i]!=ans[n-i-1]){
      f=1;
      break;
    }
  }
  if(f==0){
    //cout<<"lala";
    int x=0,y=0;
    for(i=0;i<n;i++){
      if(ans[i]=='a'){
        x=i;
        break;
      }
    }
    for(i=x;i<n;i++){
      if(ans[i]!='a'){
        y=i;
        break;
      }
    }
    //cout<<x<<y;
    for(i=0;i<x;i++)cout<<ans[i];
    for(i=x+1;i<=y;i++)cout<<ans[i];
    cout<<"a";
    for(i=y+1;i<n;i++)cout<<ans[i];
    cout<<"\n";
    return;
  }
  cout<<ans<<"\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    solve();
  }
  return 0;
}