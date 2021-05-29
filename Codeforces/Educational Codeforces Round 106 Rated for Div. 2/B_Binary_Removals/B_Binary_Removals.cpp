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
  string s; cin>>s; 
  ll n,i,j; n=s.length();
  int f=0,f1=0;
  for(i=0;i<n-1;i++){
    if(s[i]=='1'&&s[i+1]=='1'){
      f=1;
      break;
    }
  }
  i++;
  for(;i<n-1;i++){
    if(s[i]=='0'&&s[i+1]=='0'){
      f1=1;
      break;
    }
  }
  if(f&&f1){
    cout<<"NO\n";
  }
  else{
    cout<<"YES\n";
  }
  // ll i,j,n,k1,k2; cin>>n>>k1>>k2;
  // ll temp = min(k1,k2);
  // ll w,b; cin>>w>>b;
  // if(w+b!=n){
  //   cout<<"NO\n";return;
  // }
  // ll t = max(k1,k2);
  // k1 = temp;
  // k2= t;
  // if((k1+k2)%2==0 &&(k1+k2)/2 == w && (n+n-(k1+k2))%2==0 && ((2*n-(k1+k2))/2)==b){
  //   cout<<"YES\n";
  // }
  // else{
  //   cout<<"NO\n";return;
  // }
  return;
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