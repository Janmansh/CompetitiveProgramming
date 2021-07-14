#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];
vector<int>b;

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

bool check(int i, int j, int k){
  if(abs(b[k]-b[i])+abs(k-i) == abs(b[j]-b[i])+abs(j-i)+abs(b[k]-b[j])+abs(k-j)){
    return false;
  }
  return true;
}

void solve(){
  int n,i,j;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  int ans = 2*n-1;
  b.clear();
  for(i=0;i<n;i++)b.pb(a[i]);
  for(i=0;i<=n-3;i++){
    if(check(i,i+1,i+2) and check(i,i+2,i+1) and check(i+1, i, i+2) and check(i+1, i+2, i) and check(i+2, i, i+1) and check(i+2, i+1, i)){
      ans++;
    }
    
  }
  for(i=0;i<=n-4;i++){
    vector<int>temp;
    temp.pb(a[i]);
    temp.pb(a[i+1]);
    temp.pb(a[i+2]);
    if(is_sorted(temp.begin(),temp.end()) or is_sorted(temp.rbegin(),temp.rend()))continue;
    temp.clear();
    temp.pb(a[i]);
    temp.pb(a[i+1]);
    temp.pb(a[i+3]);
    if(is_sorted(temp.begin(),temp.end()) or is_sorted(temp.rbegin(),temp.rend()))continue;
    temp.clear();
    temp.pb(a[i]);
    temp.pb(a[i+2]);
    temp.pb(a[i+3]);
    if(is_sorted(temp.begin(),temp.end()) or is_sorted(temp.rbegin(),temp.rend()))continue;
    temp.clear();
    temp.pb(a[i+1]);
    temp.pb(a[i+2]);
    temp.pb(a[i+3]);
    if(is_sorted(temp.begin(),temp.end()) or is_sorted(temp.rbegin(),temp.rend()))continue;
    temp.clear();
    ans++;
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