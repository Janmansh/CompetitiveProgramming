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
  ll n,i,j,m;
  cin>>n>>m;
  m = min(m,n);
  string s;
  cin>>s;
  //int one=0;
  set<int>one;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(s[j]=='1')continue;
      if(j!=0 and j!=n-1){
        if(s[j-1]=='1' and s[j+1] == '0')one.insert(j);
        else if(s[j-1] == '0' and s[j+1] == '1')one.insert(j);
      }
      else if(j==0 and j!=n-1){
        if(s[j+1]=='1')one.insert(j);
      }
      else if(j==n-1 and j!=0){
        if(s[j-1]=='1')one.insert(j);
      }
      // if(s[i]=='1'){
      //   one.insert(i);
      //   if(i!=n-1)one.insert(i+1);
      //   if(i!=0)one.insert(i-1);
      // }
    }
    if(one.size()==0){
      cout<<s<<"\n";
      return;
    }
    for(auto it:one){
      s[it]='1';
    }
    if(one.size()==n)break;
    one.clear();
  }
  for(auto it:one){
    s[it] = '1';
  }
  cout<<s<<"\n";
  // ll a[n];
  // for(i=0;i<n;i++)cin>>a[i];
  // for(i=0;i<n-1;i++){
  //   if(a[i]==1 and a[])
  // 
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