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
  ll n,i,j;
  cin>>n;
  string s;
  cin>>s;
  ll q,f=0;
  cin>>q;
  ll t,a,b;
  while(q--){
    cin>>t>>a>>b;
    if(t==2){
      f=!f;
    }
    else if(f==0){
      char c = s[a-1];
      s[a-1] = s[b-1];
      s[b-1] = c;
    }
    else{
      a--;
      b--;
      a+=n;
      b+=n;
      a%=(2*n);
      b%=(2*n);
      char c = s[a];
      s[a] = s[b];
      s[b] = c;
    }
  }
  if(f){
    for(i=n;i<2*n;i++)cout<<s[i];
    for(i=0;i<n;i++)cout<<s[i];
    return;
  }
  else{
    for(i=0;i<n;i++)cout<<s[i];
    for(i=n;i<2*n;i++)cout<<s[i];
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
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