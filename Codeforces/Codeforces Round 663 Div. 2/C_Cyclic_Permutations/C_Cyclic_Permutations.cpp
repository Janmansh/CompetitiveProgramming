#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll m=1000000007;

ll nCrModp(ll n, ll r, ll p) 
{ 
    if (r > n - r) 
        r = n - r;
    ll C[r + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;
    for (ll i = 1; i <= n; i++) { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j - 1]) % p; 
    } 
    return C[r]; 
} 
ll power(ll x,ll y){
  if(y==0)return 1ll;
  ll temp=power(x,y/2);
  if(y%2==0){
    return (temp*temp)%m;
  }
  else{
    return (((temp*temp)%m)*x)%m;
  }
}

void solve(){
  ll i,j=1,n;
  cin>>n;
  if(n==3){
    cout<<"2\n";return;
  }
  for(i=1;i<=n;i++){
    j=j*i;
    j=j%m;
  }
  j=j-(power(2ll,n-1ll)%m);
  if(j<0)j=m+j;
  cout<<j<<"\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t;
  //cin>>t;
  t=1;
  while(t--){
    solve();
  }
}