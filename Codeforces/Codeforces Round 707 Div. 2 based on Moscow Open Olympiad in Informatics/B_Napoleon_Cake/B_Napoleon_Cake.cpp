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
  int n,i,j,c=0;
  cin>>n;
  ll a[n+1]={0},b[n+1]={0},tm[n+1]={0};
  for(i=1;i<=n;i++){
    cin>>a[i];
  }
  for(i=1;i<=n;i++){
    if(a[i]>0){
      int k = max(1ll,i-a[i]+1);
      b[k] += 1;
      if(i+1<=n)b[i+1]=-1;
    }
  }
  for(i=1;i<=n;i++)b[i]+=b[i-1];
  for(i=1;i<=n;i++){
    cout << min(1ll , b[i]) <<" ";
  }
  cout<<"\n";
  // for(i=1;i<=n;i++)cin>>tm[i];
  // for(i=1;i<=n;i++){
  //   c+=a[i]-b[i-1]+tm[i];
  //   if(i==n)break;
  //   c+=((b[i]-a[i]+1)/2);
  //   if(c<b[i]){
  //     c=b[i];
  //   }
  // }
  // cout<<c<<"\n";
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