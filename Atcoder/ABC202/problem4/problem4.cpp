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

ll NcR(int n, int r)
{

	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	long long p = 1, k = 1;

	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;

			// gcd of p, k
			long long m = __gcd(p, k);

			// dividing by gcd, to simplify
			// product division by their gcd
			// saves from the overflow
			p /= m;
			k /= m;

			n--;
			r--;
		}

		// k should be simplified to 1
		// as C(n, r) is a natural number
		// (denominator should be 1 ) .
	}

	else
		p = 1;

	// if our approach is correct p = ans and k =1
	return p;
}

void solve(){
  string s="";
  ll i,j,a,b,k;
  ll n;
  cin>>a>>b>>k;
  n = a+b;
  for(i=0;i<a;i++)s.pb('a');
  for(i=0;i<b;i++)s.pb('b');
  int start=0;
  int A=a;
  vector<int>v;
  for(j=0;j<b;j++){
  int B=b-j;
  for(i=n-B;i>=start;i--){
    ll x = A - (n-B-i);
    ll y = A - x;
    ll ncr = NcR(y+B-1, y);
    if(ncr>=k){
      v.pb(i);
      start = i+1;
      A = y;
      break;
    }
    else{
      k-=ncr;
    }
  }}
  j=0;
  for(i=0;i<n;i++){
    if(v[j]==i){
      s[i]='b';
      j++;
    }
    else{
      s[i]='a';
    }
  }
  cout<<s;
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  //srand(time(0));
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