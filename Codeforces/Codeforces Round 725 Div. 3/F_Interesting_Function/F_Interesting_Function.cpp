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
  cin>>l>>r;
  ll p[11];
  p[0]=1;
  for(i=1;i<11;i++){
    p[i] = p[i-1]*10;
  }
  ll el[11];
  for(i=0;i<11;i++)el[i]=p[i];
  for(i=1;i<11;i++)el[i]+=el[i-1];
  ll ans1 = 0;
  for(i=10;i>=0;i--){
    int x = r/p[i];
    ans1+=(x*el[i]);
    r-=(x*p[i]);
  }
  ll ans2=0;
  for(i=10;i>=0;i--){
    int x = l/p[i];
    ans2+=(x*el[i]);
    l-=(x*p[i]);
  }
  cout<<ans1-ans2<<"\n";
  // vector<int>l1,r1;
  // int x = r;
  // while(x){
  //   r1.pb(x%10);
  //   x/=10;
  // }
  // x=l;
  // while(x){
  //   l1.pb(x%10);
  //   x/=10;
  // }
  // i = 10;
  // //while(1){
  // int ans=0;
  // j = 10;
  // for(i=0;i<r1.size()-1;i++){
  //   if(i>=l1.size()){
  //     ans+=((r1[i]+1)*(j/10));
  //     j*=10;
  //     continue;
  //   }
  //   x=0;
  //   if(l1[i]>r1[i]){
  //     x = r1[i]+10 - l1[i];
  //     ans+=x+1;
  //     r1[i] = l1[i];
  //     r-=(x*(j/10));
  //   }
  //   else{
  //     x = r1[i]-l1[i];
  //     ans+=x;
  //     r1[i]=l1[i];
  //     r-=(x*(j/10));
  //   }
  //   x = r-l;
  //   x/=j;
  //   j*=10;
  //   ans+=(10*x);
  // }
  // cout<<ans<<"\n";
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