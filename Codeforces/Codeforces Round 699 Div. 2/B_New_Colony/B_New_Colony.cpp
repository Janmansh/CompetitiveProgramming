#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];

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


void solve(){
  ll n,i,j,k; cin>>n>>k;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll m=0;
  for(i=0;i<n;i++)m=max(m,a[i]);
  ll ans=0;
  for(i=0;i<n;i++)ans+=(abs(a[i]-m));
  if(ans<k){
    cout<<"-1\n";return;
  }
  ll cur=-1;
  //for(int z=0;z<100;z++){
  for(j=0;j<=10000;j++){
    for(i=0;i<n-1;i++){
      if(a[i]<a[i+1]){
        k--;
        a[i]++;
        break;
      }
    }
    if(k==0){
      cout<<i+1<<"\n";return;
    }
    if(i==n-1){
      cout<<"-1\n";return;
    }
  }
    // for(i=0;i<n-1;i++){
    //   if(a[i]<a[i+1]){
    //     k-=(i+1);
    //     i--;
    //   }
    //   if(k<=0){
    //     k+=(i+2);
    //     for(int z=i+1;z>=0;z--){
    //       k--;
    //       if(k==0){
    //         cout<<z+1<<"\n";return;
    //       }
    //     }
    //   }
    // }
  //}//}
  cout<<"-1\n";return;
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
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