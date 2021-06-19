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
  ll n,i,j;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  map<int,int>m;
  map<int,vector<int>>d;
  for(i=0;i<n-1;i++){
    m[i] = a[i+1]-a[i];
    d[m[i]].pb(i);
  }
  int ind=-1, mi = INT_MAX;
  for(auto x:m){
    if(x.second<mi){
      mi = x.second;
      ind = x.first;
    }
  }
  cout<<a[ind]<<" ";
  for(i=ind+2;i<n;i++)cout<<a[i]<<" ";
  for(i=0;i<ind;i++)cout<<a[i]<<" ";
  cout<<a[ind+1]<<"\n";
  
  
  // int ind1 = ind;
  // //int ind2 = d[mi].back();
  // if(ind1 == 0){
  //   cout<<a[ind1]<<" ";
  //   for(i=2;i<n;i++)cout<<a[i]<<" ";
  //   cout<<a[1]<<"\n";
  //   return;
  // }
  // // if(ind2==0){
  // //   cout<<a[ind2]<<" ";
  // //   for(i=2;i<n;i++)cout<<a[i]<<" ";
  // //   cout<<a[1]<<"\n";
  // //   return;
  // // }
  // if(ind1 == n-2){
  //   cout<<a[n-2]<<" ";
  //   for(i=0;i<n-2;i++)cout<<a[i]<<" ";
  //   cout<<a[n-1]<<"\n";
  //   return;
  // }
  // // if(ind2 == n-2){
  // //   cout<<a[n-2]<<" ";
  // //   for(i=0;i<n-2;i++)cout<<a[i]<<" ";
  // //   cout<<a[n-1]<<"\n";
  // //   return;
  // // }
  // //if(n==)
  // if(n==2){
  //   cout<<a[0]<<" "<<a[1]<<"\n";
  //   return;
  // }
  // cout<<a[ind1]<<" ";
  // cout<<a[n-1]<<" ";
  // for(i=0;i<ind1;i++)cout<<a[i]<<" ";
  // for(i=ind1+2;i<n-1;i++)cout<<a[i]<<" ";
  // cout<<a[ind1+1]<<"\n";
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