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
  ll n,i,j,a,b;
  cin>>n;
  int ans = 0;
  int x = (n+1)/2;
  x*=2;
  ans+=x;
  ans%=mod;
  //n/=2;
  // x = n/2;
  // int y = x/3;
  // ans+=(y*6);
  // ans%=mod;
  // ans+=((x%3)*3);
  // ans%=mod;
  // x/=3;
  // x = (x+1)/2;
  // ans+=(x*4);
  // ans%=mod;
  // int l = 12;
  // x=5;
  int l = 2;
  x=3;
  while(l<=n){
    if(l%x==0){
      x++;
      continue;
    }
    int t = n/l;
    t%=mod;
    t*=x;
    t%=mod;
    ans+=(t);
    ans%=mod;
    l = ((l*x)/(gcd(l,x)));
    t = (n)/(l);
    t%=mod;
    t*=x;
    t%=mod;
    ans-=t;
    if(ans<0)ans+=mod;
    x++;
  }
  cout<<ans<<"\n";
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