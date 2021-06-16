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
  ll n,i,j,a,b,c;
  cin>>n;
  if(n==1){
    cout<<"1\n";return;
  }
  ll ans=1000000000000000000;
  //c = n%2;
  //n-=c;
  b=0;
  j=1;
  while(j<=n){
    j*=2;
    b++;
  }
  for(i=0;i<b;i++){
    a = power(2ll,i);
    c = n/a;
    j = n-c*a;
    ans = min(ans,c+j+i);
  }
  //cout<<b<<"\n";
  //n-=(power(2ll,b-1));
  cout<<ans<<"\n";
  // while(n%2==0 && n>0){
  //   b++;
  //   n/=2;
  // }
  // cout<<b+c+n<<"\n";
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