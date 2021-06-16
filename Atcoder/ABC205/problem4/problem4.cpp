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
  ll n,i,j,q,k;
  cin>>n>>q;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  vector<int>d;
  //d[0] = a[0]-1;
  for(i=0;i<n;i++){
    d.pb(a[i]-i-1);
  }
  while(q--){
    cin>>k;
    int l=0,h=n-1;
    int y = -1;
    while(l<=h){
      int mid = (l+h)/2;
      if(d[mid] == k){
        y = mid;
        h = mid-1;
      }
      else if(d[mid]>k){
        h = mid-1;
      }
      else{
        l = mid+1;
      }
    }
    if(y!=-1){
      //int x = find(d.begin(),d.end(),k) - d.begin();
      cout<<a[y]-1<<"\n";
    }
    else{
      auto it = upper_bound(d.begin(),d.end(),k);
      if(it==d.begin()){
        cout<<k<<"\n";
      }
      else{
        it--;
        int x = it-d.begin();
        cout<<a[x]+k-d[x]<<"\n";
      }
    }
  }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
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