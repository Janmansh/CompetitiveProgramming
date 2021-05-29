#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007

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
bool check(int m,int k,int a[], int n){
  int c=1;int t=0;
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1])continue;
    t++;
    if(t==1){c++;}
    if(t==m)t=0;
  }
  if(c>k) return false;
  else return true;
}
 
               

void solve(){
  ll n,i,j,k;cin>>n>>k;
  ll a[n];
  //vector<ll>p;
  for(i=0;i<n;i++)cin>>a[i];
  // for(i=0;i<n;i++)cin>>b[i];
  // for(i=0;i<n;i++)cin>>c[i];
  int c=1;
  sort(a,a+n);
  ll ans=-1;
  for(int i=1;i<=100;i++){
    if(check(i, k, a, n)){ans=i;break;}
  }
  cout<<ans<<"\n";return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}