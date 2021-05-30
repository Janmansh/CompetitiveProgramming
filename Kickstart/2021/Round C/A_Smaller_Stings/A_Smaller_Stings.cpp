#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];
vector<string>pos;

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


void solve(){
  ll n,i,j,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int ans=0;
  for(i=0;i<(n+1)/2;i++){
    int x = n-(2*(i+1))+1;
    x/=2;
    int y = s[i]-'a';
    int l = powermod(k,x);
    l*=y;
    l%=mod;
    ans+=l;
    ans%=mod;
  }
  int f=0;
  int f1=0;
  string t;
  t=s;
  for(i=0;i<n/2;i++){
      t[n-i-1]=t[i];
  }
  if(lexicographical_compare(t.begin(),t.end(),s.begin(),s.end()))ans++;
  ans%=mod;
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  ll x=1;
  while (t--){
    cout<<"Case #"<<x<<": ";
    x++;
    solve();
  }
  return 0;
}