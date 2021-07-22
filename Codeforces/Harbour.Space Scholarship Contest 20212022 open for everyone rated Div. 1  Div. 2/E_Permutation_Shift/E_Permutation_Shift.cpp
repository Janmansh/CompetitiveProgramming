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

void swap(vector<int> &arr,
          int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int>&arr,
             int N)
{
  int ans = 0;
  vector<int>temp = arr;
 
  // Hashmap which stores the
  // indexes of the input array
  map <int, int> h;
 
  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++)
  {
    h[arr[i]] = i;
  }
  for (int i = 0; i < N; i++)
  {
    // This is checking whether
    // the current element is
    // at the right place or not
    if (arr[i] != temp[i])
    {
      ans++;
      int init = arr[i];
 
      // If not, swap this element
      // with the index of the
      // element which should come here
      swap(arr, i, h[temp[i]]);
 
      // Update the indexes in
      // the hashmap accordingly
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return ans;
}



void solve(){
  ll n,i,j,m;
  cin>>n>>m;
  ll p[n+1];
  p[0]=0;
  for(i=1;i<=n;i++)cin>>p[i];
  //int x = minSwap(p, n+1);
  map<int,int>f;
  for(i=1;i<=n;i++){
    f[(n-p[i]+i)%n]++;
  }
  vector<int>ans;
  vector<int>p1;
  int cyc = max(0ll,n/2 - n/3 - 2);
  for(i=0;i<n;i++){
    if(f[i]>=cyc){
      for(j=i;j<n;j++)
      {
          p1.pb(p[j+1]);
      }
      for(j=0;j<i;j++)
      {
          p1.pb(p[j+1]);
      }
      if(minSwaps(p1, n)<=m)ans.pb(i);
      p1.clear();
    }
  }
  cout<<ans.size()<<" ";
  for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
  cout<<"\n";
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