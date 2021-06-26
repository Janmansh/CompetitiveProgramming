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
  ll t[n],l[n],r[n];
  vector<pair<double,double>>v;
  for(i=0;i<n;i++){
    cin>>t[i]>>l[i]>>r[i];
    if(t[i]==1){
      v.pb({l[i]*1.0, r[i]*1.0});
    }
    if(t[i]==2){
      v.pb({l[i]*1.0, r[i]*1.0 - 0.1});
    }
    if(t[i]==3){
      v.pb({l[i]*1.0 + 0.1, r[i]*1.0});
    }
    if(t[i]==4){
      v.pb({l[i]*1.0 + 0.1, r[i]*1.0 - 0.1});
    }
  }
  int ans = 0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(v[i].first>v[j].second or v[i].second<v[j].first)continue;
      ans++;
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