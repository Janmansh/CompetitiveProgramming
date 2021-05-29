#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

// power function to take modulo
ll power(ll x,ll y){
  if(y==0) return 1;
  ll temp = power( x,y/2 )%mod;
  if( y%2 ){
    return (((temp*temp)%mod)*x%mod);
  }
  return (temp*temp)%mod;
}

int printNcR(int n, int r) 
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
 


void solve()
{
    ll n,i,j;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    for(i=0;i<n;i++){
      ll ax=0;
      ll cnt1[3005]={0};
      ll cnt2[3005]={0};
      int k;
      for(k=i+1;k<n;k++)cnt2[a[k]]++;
      for(k=i+1;k<n;k++){
        ax-=(cnt1[a[k]]*cnt2[a[k]]);
        cnt2[a[k]]--;
        ax+=(cnt1[a[k]]*cnt2[a[k]]);
        if(a[i]==a[k]){
          ans+=ax;
        }
        ax-=(cnt1[a[k]]*cnt2[a[k]]);
        cnt1[a[k]]++;
        ax+=(cnt1[a[k]]*cnt2[a[k]]);
      }
    }
    cout<<ans<<"\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  cin >> t;  // number of test cases
  while (t--){
    solve();
  }
  return 0;
}