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
  vector<vector<char>>s(n,vector<char>(m,'0'));
  for(i=0;i<m;i+=2){
    s[0][i] = '1';
  }
  if(m==1 or n==1){
    if(n>1)for(i=0;i<n;i+=2)s[i][0] = '1';
    for(i=0;i<n;i++){
      for(j=0;j<m;j++)cout<<s[i][j];
      cout<<"\n";
    }
    return;
  }
  for(i=0;i<n;i++){
    if(s[i][m-1] == '1')continue;
    if(i>0 and (s[i-1][m-1]=='1' or s[i-1][m-2]=='1'))continue;
    if(s[i][m-2] == '1')continue;
    s[i][m-1] = '1';
  }
  for(i=m-1;i>=0;i--){
    if(s[n-1][i] == '1')continue;
    if(i<m-1 and (s[n-1][i+1]=='1' or s[n-2][i+1]=='1'))continue;
    if(s[n-2][i] == '1')continue;
    if(i>0 and s[n-2][i-1] == '1')continue;
    s[n-1][i] = '1';
  }
  for(i=n-1;i>=0;i--){
    if(s[i][0] == '1')continue;
    if(i<n-1 and (s[i+1][0]=='1' or s[i+1][1]=='1'))continue;
    if(s[i][1] == '1')continue;
    if(i>0 and (s[i-1][0] == '1' or s[i-1][1]=='1'))continue;
    s[i][0] = '1';
  }
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)cout<<s[i][j];
    cout<<"\n";
  }
  // if(m%2){
  //   for(i=0;i<n;i+=2){
  //     s[i][m-1] = '1';
  //   }
  //   if(n%2==0){
  //     for(i=m-2;i>=0;i-=2){
  //       s[n-1][i] = '1';
  //     }
  //   }
  //   else{
  //     for(i=m-1;i>=0;i-=2){
  //       s[n-1][i] = '1';
  //     }
  //   }
  // }
  // else{
  //   for(i=1;i<n;i+=2){
  //     s[i][m-1] = '1';
  //   }
  //   if(n%2==0){
  //     for(i=m-2;i>=0;i-=2){
  //       s[n-1][i] = '1';
  //     }
  //   }
  //   else{
  //     for(i=m-1;i>=0;i-=2){
  //       s[n-1][i] = '1';
  //     }
  //   }
  // }
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