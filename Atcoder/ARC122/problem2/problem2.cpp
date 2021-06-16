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
  ll i,j,n;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  double ans = 0;
  if(n%2){
    int ind = n/2;
    double x = (a[ind]*1.0/2.0);
    for(i=0;i<n;i++){
      ans+=(double(max(a[i]*1.0-x, x)));
    }
    ans = ans/n*1.0;
    cout<<fixed<<setprecision(20)<<ans<<"\n";return;
  }
  else{
    double ans1=0;
    int ind = n/2;
    int ind1 = ind-1;
    double x = (a[ind]*1.0/2.0);
    double x1 = (a[ind1]*1.0/2.0);
    for(i=0;i<n;i++){
      ans+=(double(max(a[i]*1.0-x, x)));
      ans1+=(double(max(a[i]*1.0-x1, x1)));
    }
    ans = ans/n*1.0;
    ans1 = ans1/n*1.0;
    ans = double(min(ans,ans1));
    cout<<fixed<<setprecision(20)<<ans<<"\n";return;
  }
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