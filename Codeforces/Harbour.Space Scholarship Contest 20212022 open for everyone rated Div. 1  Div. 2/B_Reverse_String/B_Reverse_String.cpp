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


void solve(){
  ll n,i,j, k;
  string s, t;
  cin>>s>>t;
  n = s.length();
  int m = t.length();
  for(i=0;i<n;i++){
    if(s[i] == t[0]){
      for(j=0;j<=min(n-i, m);j++){
        int x = m-j;
        string l = "";
        if(x<=n and i+j-x+1>=0 and i+j+1<=n)l = s.substr(i+j-x+1,x);
        reverse(l.begin(), l.end());
        string r = "";
        if(j>0 and i+j<=n)r = s.substr(i,j);
        r.append(l);
        //cout<<r<<" ";
        if(r == t){
          cout<<"Yes\n";return;
        }
      }
    }
  }
  cout<<"No\n";return;
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
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