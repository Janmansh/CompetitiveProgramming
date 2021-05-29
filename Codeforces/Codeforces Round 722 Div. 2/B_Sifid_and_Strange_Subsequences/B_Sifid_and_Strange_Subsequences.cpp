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
  ll a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int c=0;
  int f=0;
  int z=0;
  int man=INT_MIN;
  int mip=INT_MAX;
  int mi=INT_MAX;
  for(i=0;i<n;i++){
    if(a[i]<0){
      if(i>0){
        mi = min(mi,abs(a[i]-a[i-1]));
      }
      c++;
      man = max(man,a[i]);
    }
    if(a[i]>0){
      f=1;
      mip=min(mip,a[i]);
    }
    if(a[i]==0)z++;
  }
  if(mip>mi){
    cout<<max(1ll,c+z)<<"\n";return;
  }
  int ans=c+z;
  ans = max(ans,c+f);
  if(mip<=(-1*man)){
    ans = max(ans,c+min(z,1ll)+f);
  }
  cout<<ans<<"\n";
  //if(z>1)cout<<max(1ll,c+z)<<"\n";
  //else if(z==1)cout<<max(1ll,c+z+f)<<"\n";
  
  //cout<<max(1ll,c+max(z,f))<<"\n";
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