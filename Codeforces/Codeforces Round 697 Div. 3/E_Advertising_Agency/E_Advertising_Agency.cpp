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
  ll n,A,B,k,i,j; cin>>n>>k;
  ll a[n];
  //ll a[k],b[k];
  map<int,int>f,s;
  map<pair<int,int>,int>p;
  for(i=0;i<n;i++){cin>>a[i];}//f[a[i]]++;}
  sort(a,a+n);
  for(i=0;i<n;i++){f[a[i]]++;s[a[i]]=0;}
  for(i=n-1;i>=n-k;i--){
      s[a[i]]++;
  }
  ll ans=1;
  ll freq[n+1]={0};
  for(i=0;i<n;i++){
      if(s[a[i]]==0||freq[a[i]])continue;
      freq[a[i]]=1;
      ans*=(nCr(f[a[i]],s[a[i]],mod));
      ans%=mod;
  }
  cout<<ans<<"\n";
  //for(i=0;i<k;i++){cin>>b[i];s[b[i]]++;p[mp(a[i],b[i])]++;}
  
//   vector<pair<int,int>>v;
//   int ans=0;
//   for(i=0;i<k;i++){
//       ans+=(k-f[a[i]]-s[b[i]]+p[mp(a[i],b[i])]);
//   }
//   ans/=2;
//   cout<<ans<<"\n";
//   return;
  
//   if(n<2020){
//       cout<<"NO\n";return;
//   }
//   a=n/2020;
//   b=n%2020;
//   if(b<=a){
//       cout<<"YES\n";return;
//   }
//   cout<<"NO\n";
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