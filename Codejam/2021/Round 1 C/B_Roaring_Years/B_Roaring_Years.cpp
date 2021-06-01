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
  ll n,k,i,j;
  cin>>n>>k;
  ll p[n];
  for(i=0;i<n;i++)cin>>p[i];
  sort(p,p+n);
  vector<int>kk,vv;
  kk.pb(p[0]-1);
  for(i=1;i<n;i++){
      ll xx = (p[i]-p[i-1])/2;
      vv.pb(p[i]-p[i-1]-1);
      kk.pb(xx);
  }
  sort(vv.begin(),vv.end(),greater<int>());
  kk.pb(k-p[n-1]);
  sort(kk.begin(),kk.end(),greater<int>());
  ll cc = kk[0] + kk[1];
  if(vv.size()>0){cc = max(cc,vv[0]);}
//   vector<pair<int,int>>v;
//   for(i=1;i<=k;i++){
//       for(j=i;j<=k;j++){
//           v.pb(mp(i,j));
//       }
//   }
  double ans=0;
//   ll mi[k];
//   for(i=1;i<=k;i++){
//       mi[i-1] = abs(p[0]-i);
//       for(j=1;j<n;j++){
//           mi[i-1] = min(mi[i-1],abs(p[j]-i));
//       }
//   }
//   for(i=0;i<v.size();i++){
//       ll c=0;
//       for(j=1;j<=k;j++){
//           if(abs(v[i].first - j) < mi[j-1] || abs(v[i].second - j) < mi[j-1]){
//               c++;
//           }
//       }
//       double tt = (c*1.0)/(k*1.0);
//       ans = max(ans,tt);
//   }
  double tt = (cc*1.0)/(k*1.0);
  ans = tt;
  cout << fixed << setprecision(20) << ans << "\n";
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
  ll x=1;
  while (t--){
    cout<<"Case #" << x <<": ";
    x++;
    solve();
  }
  return 0;
}