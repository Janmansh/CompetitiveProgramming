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
  ll n,m,i,j;
  cin>>n>>m;
  ll a[n],b[n],s[m];
  set<int>d;
  for(i=0;i<n;i++){
    cin>>a[i]>>b[i];
    for(j=a[i];j<=b[i];j++)d.insert(j);
  }
  for(i=0;i<m;i++)cin>>s[i];
  ll p[m];
  for(i=0;i<m;i++){
    auto it = lower_bound(d.begin(),d.end(), s[i]);
    if(it==d.begin()){
      p[i] = (*it);
      d.erase(it);
    }
    else if(it==d.end()){
      it--;
      p[i] = (*it);
      d.erase(it);
    }
    else{
      auto it1 = it;
      it1--;
      int mi = (*it);
      int mi1 = (*it1);
      if(abs(s[i]-mi1)<=abs(mi-s[i])){
        p[i] = mi1;
        d.erase(it1);
      }
      else{
        p[i] = mi;
        d.erase(it);
      }
    }
  }
  for(i=0;i<m;i++)cout<<p[i]<<" ";
  cout<<"\n";
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