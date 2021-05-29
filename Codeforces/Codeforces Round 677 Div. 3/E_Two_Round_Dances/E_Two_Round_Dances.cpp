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

int NcR(int n, int r) 
{ 
  
    // p holds the value of n*(n-1)*(n-2)..., 
    // k holds the value of r*(r-1)... 
    long long p = 1, k = 1; 
  
    // C(n, r) == C(n, n-r), 
    // choosing the smaller value 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            // gcd of p, k 
            long long m = __gcd(p, k); 
  
            // dividing by gcd, to simplify product 
            // division by their gcd saves from the overflow 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
  
        // k should be simplified to 1 
        // as C(n, r) is a natural number 
        // (denominator should be 1 ) . 
    } 
  
    else
        p = 1; 
  
    // if our approach is correct p = ans and k =1 
    return p; 
} 

void solve(){
  ll x,i,j,n; cin>>n;// ll a[n],b[n];x=0; vector<ll>v;
  ll ans=NcR(n,n/2);
  ans/=2;
  for(i=1;i<n/2;i++)ans*=i;
  for(i=1;i<n/2;i++)ans*=i;
  cout<<ans<<"\n";
  // for(i=0;i<n;i++){
  //   cin>>a[i];
  //   b[i]=a[i];
  // }
  // sort(b,b+n);
  // x=b[n-1];
  // if(b[0]==b[n-1]){
  //   cout<<"NO\n";return;
  // }
  // cout<<"YES\n";
  // for(i=1;i<n;i++){
  //   if(a[i]!=a[0]){
  //     j=i;
  //     cout<<"1 "<<i+1<<"\n";
  //   }
  // }
  // for(i=1;i<n;i++){
  //   if(a[i]==a[0]){
  //     cout<<j+1<<" "<<i+1<<"\n";
  //   }
  // }
  // return;
  // for(i=0;i<n;i++){
  //   if(a[i]==x){
  //     if(i==0){
  //       if(a[i+1]!=x){
  //         cout<<"1\n";return;
  //       }
  //     }
  //     else if(i==n-1){
  //       if(a[i-1]!=x){
  //         cout<<n<<"\n";return;
  //       }
  //     }
  //     else{
  //       if(a[i+1]!=x||a[i-1]!=x){
  //         cout<<i+1<<"\n";return;
  //       }
  //     }
  //   }
  // }
  // cout<<"-1\n";
  // return;
  // ll ans=0;
  // for(i=0;i<v.size()-1;i++){
  //   if(v[i]==v[i+1]-1)continue;
  //   else{
  //     ans+=(v[i+1]-v[i]-1);
  //   }
  // }
  // cout<<ans<<"\n";
  //return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}