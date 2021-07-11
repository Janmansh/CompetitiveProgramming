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
  ll n,i,j,c;
  cin>>n>>c;
  ll l[n],r[n];
  int lo=1,hi=0;
  for(i=0;i<n;i++){
    cin>>l[i]>>r[i];
    hi = max(hi,r[i]);
  }
  vector<int>v;
  for(i=lo;i<=hi;i++){
    int co=0;
    for(j=0;j<n;j++){
      if(l[j]<i and r[j]>i)co++;
    }
    if(co>0)v.pb(co);
  }
  sort(v.begin(),v.end());
  int ans=n;
  for(i=v.size()-1;i>=0;i--){
    if(c==0)break;
    ans+=v[i];
    //cout<<v[i]<<" ";
    c--;
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  int x=1;
  //srand(time(0));
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    cout<<"Case #"<<x<<": ";
    solve();
    x++;
  }
  return 0;
}