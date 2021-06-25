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
  ll n,k,x,i,j;
  cin>>n>>k>>x;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int ans=0;
  int mi = a[0];
  int k1 = k;
  vector<int>v;
  for(i=1;i<n;i++){
    if(a[i]-a[i-1]<=x){
      continue;
    }
    else{
      //if(k>0){
        int l = ceil(1.0*(a[i]-a[i-1])/(1.0*x));
        l--;
        v.pb(l);
        //if(k>=l)k-=l;
        //else{
          //ans++;
        //}
        //mi = a[i];
      //}
      //else{
        //ans++;
        //mi = a[i];
      //}
    }
  }
  sort(v.begin(),v.end());
  ans = v.size()+1;
  for(i=0;i<v.size();i++){
    if(v[i]<=k){
      ans--;
      k-=v[i];
    }
  }
  cout<<ans;
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