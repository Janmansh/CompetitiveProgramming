#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
int coun[20000001]={0};

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

void calc(){
  for(int i=2;i<20000001;i++){
    if(coun[i])continue;
    for(int j=i;j<20000001;j+=i){
      coun[j]++;
    }
  }
}
  

void solve(){
  ll x,c,d,i,j;
  cin>>c>>d>>x;
  set<int>fac;
  for(i=1;i<=sqrt(x);i++){
    if(x%i==0){
      fac.insert(i);
      fac.insert(x/i);
    }
  }
  ll ans=0;
  for(auto t:fac){
    int alpha = x/t;
    if((d+alpha)%c==0){
      ll beta = (alpha+d)/c;
      ans+=(1<<coun[beta]);
    }
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  calc();
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