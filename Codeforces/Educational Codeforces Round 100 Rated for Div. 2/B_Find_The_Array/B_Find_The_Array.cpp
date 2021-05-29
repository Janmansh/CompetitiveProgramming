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
  ll n,i,j; cin>>n; ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll s=0;
  ll aa[60];
  for(i=0;i<60;i++)aa[i]=power(2ll,i);
  for(i=0;i<n;i++)s+=a[i];
  ll b[n];
  for(i=0;i<n;i++){
    b[i]=1;
    ll m=a[i]-1;
    ll z=0;
    for(j=1;j<30;j++){
      if(abs(a[i]-aa[j])<m){
        m=abs(a[i]-aa[j]);
        b[i]=aa[j];
      }
    }
  }
  for(i=0;i<n;i++)cout<<b[i]<<" ";
  cout<<"\n";
  // for(i=0;i<n-1;i++){
  //   if(b[i]%b[i+1]==0||b[i+1]%b[i]==0)continue;
    
  // }
  // for(i=0;i<n;i++){
  //   if(a[i]==1)continue;
  //   for(j=0;j<n;j++)if(b[j]!=1)b[j]=a[i];
  // ll ss=0;
  // for(j=0;j<n;j++){
  // ss+=(abs(a[j]-b[j]));
  // }
  // ss*=2;
  // if(ss<=s)cout<<"lala";
  // }
  // for(i=0;i<n;i++)cout<<b[i]<<" ";
  // cout<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  fact[0]=1;
  for(int i=1;i<200001;i++){
    fact[i]=i*fact[i-1];
    fact[i]%=mod;
  }
  while (t--){
    solve();
  }
  return 0;
}