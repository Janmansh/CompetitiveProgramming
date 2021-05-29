#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define double long double

//ll fact[200005];

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

// Prime[] array to calculate Prime Number 
int prime[1000001] = { 0 }; 
  
// Array k[] to store the value of k for 
// each element in arr[] 
int k[1000001] = { 0 }; 
  
// For value of k, Sieve function is 
// implemented 
void Sieve() 
{ 
    // Initialize k[i] to i 
    for (int i = 1; i < 1000001; i++) 
        k[i] = i; 
  
    // Prime Sieve 
    for (int i = 2; i < 1000001; i++) { 
  
        // If i is prime then remove all 
        // factors of prime from it 
        if (prime[i] == 0) 
            for (int j = i; j < 1000001; j += i) { 
  
                // Update that j is not 
                // prime 
                prime[j] = 1; 
  
                // Remove all square divisors 
                // i.e. if k[j] is divisible 
                // by i*i then divide it by i*i 
                while (k[j] % (i * i) == 0) 
                    k[j] /= (i * i); 
            } 
    } 
}


void solve(){
  ll n,i,j; cin>>n;
  ll a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
    a[i]=k[a[i]];
  }
  map<int,int>m;
  ll maxi=0;
  for(i=0;i<n;i++)m[a[i]]++;
  for(auto it:m){
    maxi=max(maxi,it.second);
  }
  ll q,w; cin>>q;
  ll e=0;
  for(auto it:m){
    if(it.second%2==0)e+=it.second;
  }
  if(m[1]%2)e+=m[1];
  while(q--){
    cin>>w;
    if(w==0){
      cout<<maxi<<"\n";
    }
    else{
      cout<<max(e,maxi)<<"\n";
    }
  }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  Sieve();
  while (t--){
    solve();
  }
  return 0;
}