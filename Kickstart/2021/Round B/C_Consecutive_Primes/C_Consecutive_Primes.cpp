#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];
vector<int>prime;

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

bool isProduct(int num)
{
    int cnt = 0;
 
    for (int i = 2; cnt < 2 && i * i <= num; ++i) {
        while (num % i == 0) {
            num /= i;
            ++cnt;
        }
    }
 
    if (num > 1)
        ++cnt;
 
    return cnt == 2;
}

void solve(){
  ll n,i,j;
  cin>>n;
//   auto it = upper_bound(prime.begin(),prime.end(),n);
//   it--;
//   j = it-prime.begin();
  ll ans=1;
  i=0;
  int low=1,hi=n;
  
  cout<<ans<<"\n";
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
  ll tt=10000000;
  //SieveOfAtkin(tt);
  ll x=1;
  while (t--){
    cout << "Case #" << x << ": ";
    x++;
    solve();
  }
  return 0;
}