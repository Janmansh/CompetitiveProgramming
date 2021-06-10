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
  ll n,i,j,l,r;
  cin>>n>>l>>r;
  ll a[n];
  vector<int>v;
  for(i=0;i<n;i++){
    cin>>a[i];
    v.pb(a[i]);
  }
  sort(v.begin(),v.end());
  ll ans=0;
  if(n==1){
    cout<<"0\n";return;
  }
  for(i=0;i<n-1;i++){
    int x = 0;
    auto it1 = upper_bound(v.begin()+i+1,v.end(),r-v[i]);
    if(it1==v.begin()+i+1){
      continue;
    }
    it1--;
    //auto it = find(v.begin(),v.end(),v[i]);
    auto it2 = lower_bound(v.begin()+i+1,v.end(),l-v[i]);
    //if(it==it2 or it==it1 or v[i]>(*it2) and v[i]<(*it1))x--;
    if(it2==v.begin()+1+i){
      //if(it==it2 or it==it1 or v[i]>(*it2) and v[i]<(*it1))x--;
      x += it1-it2;
      ans+=(max(0ll,x+1));
      continue;
    }
    else{
      it2--;
    }
    //auto it3 = it2;
    //it3++;
    //if(it3==it or it==it1 or v[i]>(*it2) and v[i]<(*it1))x--;
    x += it1-it2;
    ans+=(max(0ll,x));
  }
  cout<<ans<<" ";
  //cout<<ans/2<<"\n";
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