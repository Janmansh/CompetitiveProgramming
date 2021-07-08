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


double solution(double c, double m, double p, double v, int co, double cur){
  double ans=0;
  double x = 0;
  double p_pro = cur*p;
  ans+=(p_pro*(co+1));
  double p_c = cur*c;
  double p_m = cur*m;
  if(c<=0.000000001 and m<=0.000000001)return ans;
  if(c>0.000000001 and m>0.000000001){
    if(c-v>0.000000001){
      ans+=(solution(c-v, m+v/2.0, p+v/2.0, v, co+1, p_c));
    }
    else{
      ans+=(solution(x, m+c/2.0, p+c/2.0, v, co+1, p_c));
    }
    if(m-v>0.000000001){
      ans+=(solution(c+v/2.0, m-v, p+v/2.0, v, co+1, p_m));
    }
    else{
      ans+=(solution(c+m/2.0, x, p+m/2.0, v, co+1, p_m));
    }
  }
  if(c>0.000000001 and m<=0.000000001){
    if(c-v>0.000000001){
      ans+=(solution(c-v, x, p+v, v, co+1, p_c));
    }
    else{
      ans+=(solution(x, x, p+c, v, co+1, p_c));
    }
  }
  if(m>0.000000001 and c<=0.000000001){
    if(m-v>0.000000001){
      ans+=(solution(x, m-v, p+v, v, co+1, p_m));
    }
    else{
      ans+=(solution(x, x, p+m, v, co+1, p_m));
    }
  }
  return ans;
}


void solve(){
  ll n,i,j;
  double c,m,p,v;
  cin>>c>>m>>p>>v;
  double ans=0;
  cout<<fixed<<setprecision(20)<<solution(c,m,p,v,0, 1.0)<<"\n";
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