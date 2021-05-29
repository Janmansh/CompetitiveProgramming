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

bool valu(tuple<int,int,int>a, tuple<int,int,int>b){
  return ((get<0>(a))>(get<0>(b)));
}


void solve(){
  ll i,j,n,a,b;
  cin>>n;
  ll k[n];
  vector<tuple<int,int,int>>v;
  for(i=0;i<n;i++){
    cin>>k[i];
  }
  
  //vector<tuple>nc;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(k[i] <= k[j]) v.pb(make_tuple(abs(k[j]-k[i]), i, j));
      else v.pb(make_tuple(abs(k[j]-k[i]), j, i));
    }
  }
  
  sort(v.begin(), v.end(), valu);
  
  for(i=0;i<v.size();i++){
    //if(k[get<1>(v[i])] == 0)continue;
    cout << "? " << get<2>(v[i])+1 << " " << get<1>(v[i])+1 <<"\n";
    cout.flush();
    string s;
    cin >> s;
    if(s == "Yes"){
      cout << "! " << get<1>(v[i])+1 << " " << get<2>(v[i])+1 <<"\n";
      cout.flush();
      return;
    }
  }
  cout<<"! 0 0"<<"\n"; cout.flush();
  
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