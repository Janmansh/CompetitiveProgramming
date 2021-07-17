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
  ll a[n], b[n];
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n;i++)cin>>b[i];
  ll A[n], B[n];
  sort(a,a+n, greater<int>());
  sort(b,b+n, greater<int>());
  for(i=0;i<n;i++){
    A[i] = a[i];
    B[i] = b[i];
  }
  int ans = 0;
  int sa = 0, sb = 0;
  for(i=1;i<n;i++)a[i]+=a[i-1];
  for(i=1;i<n;i++)b[i]+=b[i-1];
  int x = n - (n/4);
  //cout<<x<<" ";
  sa = a[x-1];
  sb = b[x-1];
  int d = x-1;
  int h = 0;
  //cout<<sa<<" ";
  int N = n;
  while(sa<sb){
    ans++;
    N++;
    x = N - (N/4);
    if(x>=n){
      sb = b[n-1]; 
    }
    else{
      sb = b[x-1];
    }
    //cout<<sb<<" ";
    h++;
    d = x - h;
    sa = 0;
    //cout<<d<<" ";
    if(d>=1 and d<=n){
      sa+=a[d-1];
    }
    sa+=(min(h,x)*100);
    //cout<<sa<<" ";
    // if(ans == 3){
    //   cout<<sa<<" "<<sb<<" ";
    // }
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