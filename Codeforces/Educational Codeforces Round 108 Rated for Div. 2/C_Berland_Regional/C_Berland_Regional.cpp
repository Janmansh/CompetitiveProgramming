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
  ll n,i,j,k;
  cin>>n;
  ll ans=0;
  ll u[n],s[n];
  map<int,int>m;
  map<int,vector<int>>uni;
  for(i=0;i<n;i++){cin>>u[i];m[u[i]]++;}
  vector<int>v;
  for(i=0;i<n;i++){
    cin>>s[i];
    uni[u[i]] = v;
  }
  for(i=0;i<n;i++)uni[u[i]].pb(s[i]);
  for(auto it: uni){
    v = it.second;
    sort(v.begin(), v.end(), greater<int>());
    uni[it.first] = v;
    //sort(it.second.begin(), it.second.end(), greater<int>());
  }
  for(auto it: uni){
    v = it.second;
    for(i=1;i<v.size();i++){
      v[i]+=v[i-1];
    }
    uni[it.first] = v;
  }
  // for(auto it: uni){
  //   cout<<it.first<<": ";
  //   for(i=0;i<it.second.size();i++){
  //     cout<<it.second[i]<<" ";
  //   }
  //   cout<<"\n";
  // }
  ll answer[n]={0};
  for(auto it: uni){
    v = it.second;
    k = v.size();
    for(i=1;i<=k;i++){
      answer[i-1]+=v[k-1-(k%i)];
    }
  }
  for(i=0;i<n;i++)cout<<answer[i]<<" ";
  // for(i=1;i<=n;i++){
  //   ans=0;
  //   if(uni.size()>)
  //   for(auto it: uni){
  //     k = it.second.size();
  //     if(k>=i){
  //       ans+=it.second[k-1-(k%i)];
  //     }
  //   }
  //   cout<<ans<<" ";
  // }
  cout<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
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