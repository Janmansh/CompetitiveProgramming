#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
//vector<ll>pr;

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


// void SieveOfEratosthenes(int n) 
// { 
//     // Create a boolean array "prime[0..n]" and initialize 
//     // all entries it as true. A value in prime[i] will 
//     // finally be false if i is Not a prime, else true. 
//     bool prime[n+1]; 
//     memset(prime, true, sizeof(prime)); 
  
//     for (int p=2; p*p<=n; p++) 
//     { 
//         // If prime[p] is not changed, then it is a prime 
//         if (prime[p] == true) 
//         { 
//             // Update all multiples of p greater than or  
//             // equal to the square of it 
//             // numbers which are multiple of p and are 
//             // less than p^2 are already been marked.  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
  
//     // Print all prime numbers 
//     for (int p=2; p<=n; p++) 
//       if (prime[p]) 
//           pr.pb(p);// << " "; 
// }

void solve(){
  ll n,i,j,k; string a,b; cin>>n>>k;
  cin>>a>>b;
  int fa[26]={0},fb[26]={0},ex[26]={0};
  for(i=0;i<n;i++){
    fa[a[i]-'a']++;fb[b[i]-'a']++;
  }
  int f=1;
  for(i=0;i<26;i++){
    if(fa[i]!=fb[i]){
      ex[i]=fb[i]-fa[i];
      f=0;
    }
  }
  if(f){
    cout<<"Yes\n";return;
  }
  f=1;
  ll ne=0,po=0;
  for(i=0;i<26;i++){
    if(ex[i]%k!=0){
      f=0;
      break;
    }
  }
  ll ss=0;
  for(i=0;i<26;i++){
    ss+=ex[i];
    if(ss>0){
      f=0;
      break;
    }
  }
  if(f){
    cout<<"Yes\n";
  }
  else cout<<"No\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  //SieveOfEratosthenes(100000);
  while (t--){
    solve();
  }
  return 0;
}