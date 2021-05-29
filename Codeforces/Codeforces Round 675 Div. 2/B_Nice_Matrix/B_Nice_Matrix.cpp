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
  ll n,m,i,j,z;
  cin>>n>>m;
  ll a[n][m];
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)cin>>a[i][j];
  }
  vector<ll>d;
  ll ans2=0;
  for (ll k=0;k<=n/2;k++)
    {
        for (ll l=0;l<=m/2;l++)
        {
        
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++)
            {
                ll x=min(i,n-i-1);
                ll y=min(j,m-1-j);
                if (x==k && y==l)
                {
                    d.pb(a[i][j]);
                }
            }
        }
        
        sort(d.begin(),d.end());
        
        ll m=d[d.size()/2];
        for (ll h=0;h<d.size();h++)
        {
            ans2+=abs(m-d[h]);
        }
        
        d.clear();
        
        }
    }
  // for(i=0;i<n/2;i++){
  //   for(j=0;j<m/2;j++){
  //     vector<ll> d;
  //     d.pb(a1[i][j]);
  //     d.pb(a1[n-i-1][j]);
  //     d.pb(a1[i][m-j-1]);
  //     d.pb(a1[n-i-1][m-j-1]);
  //     ans2+=(abs(a1[i][j]-d[1])+abs(a1[n-i-1][j]-d[1])+abs(a1[n-i-1][m-j-1]-d[1])+abs(a1[i][m-j-1]-d[1]));
  //   }
  // }
  // if(m%2){
  //   for(i=0;i<n/2;i++){
  //     ans2+=(abs(a1[i][m/2]-a1[n-i-1][m/2]));
  //   }
  // }
  // if(n%2){
  //   for(i=0;i<m/2;i++){
  //     ans2+=(abs(a1[n/2][m-i-1]-a1[n/2][i]));
  //   }
  // }
  cout<<ans2<<"\n";return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}