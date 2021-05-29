#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define double long double

//ll fact[200005];
vector<int>prim;

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

// int gcd (int a, int b) {
//     return b ? gcd (b, a % b) : a;
// }

// ll inv(ll a, ll p){
// 	return powermod(a,mod-2);
// }
 
// ll nCr(ll n, ll r, ll p){
// 	if(r > n) return 0;
// 	ll t1 = fact[n];
// 	ll t2 = inv(fact[r],p);
// 	ll t3 = inv(fact[n-r],p);
 
// 	return (((t1*t2)%p)*t3)%p;
// }


void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          prim.pb(p); 
} 

void solve(){
  ll n,i,j,d; cin>>d;
  n=1;
  j=0;
  ll l=1;
  for(i=0;i<prim.size();i++){
    //if(prime[i]==2)continue;
    if(prim[i]>=l+d){n*=prim[i];l=prim[i];j++;}
    if(j==2)break;
  }
  cout<<n<<"\n";
  // string a,b;
  // cin>>b;
  // a.pb('1');
  // a[0]-=48;
  // for(i=0;i<n;i++)b[i]-=48;
  // for(i=1;i<n;i++){
  //   a.pb(1);
  //   if(a[i]+b[i]==b[i-1]+a[i-1])a[i]-=1;
  // }
  // for(i=0;i<n;i++){
  //   a[i]+=48;
  // }
  // cout<<a<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  SieveOfEratosthenes(1000000);
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