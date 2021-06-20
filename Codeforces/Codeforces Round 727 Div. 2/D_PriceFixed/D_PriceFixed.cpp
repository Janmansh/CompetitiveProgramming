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
  ll a[n],b[n];
  for(i=0;i<n;i++)cin>>a[i]>>b[i];
  vector<pair<int,int>>v;
  for(i=0;i<n;i++){
    v.pb(mp(a[i],b[i]));
  }
  int buy = 0;
  sort(v.begin(),v.end(), [&](pair<int,int>a, pair<int,int>b){
    if(a.second==b.second)return a.first<=b.first;
    return a.second<b.second;
  });
  j = n-1;
  int ans=0;
  for(i=0;i<n;i++){
    if(i>j)break;
    if(v[i].second<=buy){
      ans+=v[i].first;
      buy+=v[i].first;
      continue;
    }
    int x = v[i].second;
    while(i<=j and buy<v[i].second){
      int temp = min(v[j].first, v[i].second-buy);
      ans+=(2*temp);
      buy+=temp;
      v[j].first-=temp;
      if(v[j].first==0)j--;
    }
    if(v[i].first==0)break;
    ans+=(v[i].first);
    buy+=v[i].first;
  }
  cout<<ans<<"\n";
  // i=0;
  // while(j>=i){
    
  // }
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