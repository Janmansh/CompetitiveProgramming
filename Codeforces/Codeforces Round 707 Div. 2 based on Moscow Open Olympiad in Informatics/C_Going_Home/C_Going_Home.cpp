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
  ll i,j,n,k; cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  map<int,pair<int,int>>m;
  int flag=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      ll s=a[i]+a[j];
      if(m.find(s)==m.end()){
        m[s] = mp(i+1,j+1);
      }
      else{
        set<int>pairs;
        pairs.insert(i+1);
        pairs.insert(j+1);
        pairs.insert(m[s].first);
        pairs.insert(m[s].second);
        if(pairs.size()==4){
          pair<int,int>p;
          p = m[s];
          cout<<"YES\n"<<p.first<<" "<<p.second<<" "<<i+1<<" "<<j+1<<"\n";
          flag=1;
          break;
        }
      }
    }
    if(flag)break;
  }
  if(flag==0){
    cout<<"NO\n";
  }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
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