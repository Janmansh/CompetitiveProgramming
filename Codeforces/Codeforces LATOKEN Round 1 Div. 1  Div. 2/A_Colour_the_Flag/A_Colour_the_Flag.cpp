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
  ll n,i,j,m;
  cin>>n>>m;
  string a[n],b[n],c[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  int f = 0;
  for(i=0;i<n;i++){
    b[i] = "";
    c[i] = "";
    for(j=0;j<m;j++){
      if(f%2){
        b[i].pb('W');
        c[i].pb('R');
      }
      else{
        b[i].pb('R');
        c[i].pb('W');
      }
      f = 1-f;
    }
    if(m%2==0){
      f = 1-f;
    }
  }
  int b1 = 0;
  int c1 = 0;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(a[i][j]!='.' and a[i][j]!=b[i][j])b1 = 1;
      if(a[i][j]!='.' and a[i][j]!=c[i][j])c1=1;
    }
  }
  if(b1 and c1){
    cout<<"No\n";return;
  }
  cout<<"Yes\n";
  if(b1==0){
    for(i=0;i<n;i++)cout<<b[i]<<"\n";
  }
  else{
    for(i=0;i<n;i++)cout<<c[i]<<"\n";
  }
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