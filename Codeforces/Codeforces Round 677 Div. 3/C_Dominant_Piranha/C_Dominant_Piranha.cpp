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


void solve(){
  ll x,i,j,n; cin>>n; ll a[n],b[n];x=0; vector<ll>v;
  for(i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(b,b+n);
  x=b[n-1];
  if(b[0]==b[n-1]){
    cout<<"-1\n";return;
  }
  for(i=0;i<n;i++){
    if(a[i]==x){
      if(i==0){
        if(a[i+1]!=x){
          cout<<"1\n";return;
        }
      }
      else if(i==n-1){
        if(a[i-1]!=x){
          cout<<n<<"\n";return;
        }
      }
      else{
        if(a[i+1]!=x||a[i-1]!=x){
          cout<<i+1<<"\n";return;
        }
      }
    }
  }
  cout<<"-1\n";
  return;
  // ll ans=0;
  // for(i=0;i<v.size()-1;i++){
  //   if(v[i]==v[i+1]-1)continue;
  //   else{
  //     ans+=(v[i+1]-v[i]-1);
  //   }
  // }
  // cout<<ans<<"\n";
  return;
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