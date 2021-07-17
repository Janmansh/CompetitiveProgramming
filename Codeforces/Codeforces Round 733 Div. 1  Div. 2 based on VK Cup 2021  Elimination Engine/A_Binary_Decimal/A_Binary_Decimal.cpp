#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];
int answer = 0;

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

void psuedoBinary(int n)
{
    // Repeat below steps until n > 0
    while (n > 0)
    {                
        // calculate m (A number that has same
        // number of digits as n, but has 1 in
        // place of non-zero digits 0 in place
        // of 0 digits)
        int temp = n, m = 0, p = 1;
        while (temp)
        {
            int rem = temp % 10;
            temp = temp / 10;
 
            if (rem != 0)
                m += p;
             
            p *= 10;
        }
         
        answer++;
 
        // subtract m from n
        n = n - m;
    }
}

void solve(){
  ll n,i,j;
  cin>>n;
  answer = 0;
  psuedoBinary(n);
  cout<<answer<<"\n";
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