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

bool bol(pair<int,int>a,pair<int,int>b){
  if(a.first!=b.first)return a.first>b.first;
  return a.second<b.second;
}

void solve(){
  ll n,i,j;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  priority_queue<int, vector<int>, greater<int> > negative;
  ll sum=0;
  int ans=0;
  for(i=0;i<n;i++){
    if(sum+a[i]<0 and negative.size()==0)continue;
    if(sum+a[i]>=0 and a[i]>=0){
      ans++;
      sum+=a[i];
      continue;
    }
    if(sum + a[i] >= 0 and a[i]<0){
      negative.push(a[i]);
      sum+=a[i];
      ans++;
      continue;
    }
    int x = negative.top();
    if(x<=a[i]){
      sum+=a[i];
      sum-=x;
      negative.pop();
      negative.push(a[i]);
    }
  }
  cout<<ans<<"\n";
  
  // vector<pair<int,int>>neg;
  // for(i=0;i<n;i++){
  //   if(a[i]<0)neg.pb(mp(a[i],i));
  // }
  // sort(neg.begin(),neg.end(),bol);
  // ll ans=0;
  // j=0;
  // //for(i=1;i<n;i++)a[i]+=a[i-1];
  // for(i=0;i<n;i++){
  //   if(a[i]>=0)ans++;
  // }
  // int sub=0;
  // ll f[n] = {0};
  // set<int>ss;
  // ll b[n];
  // for(i=0;i<n;i++){
  //   b[i] = max(0ll, a[i]);
  // }
  // for(i=1;i<n;i++){
  //   b[i]+=b[i-1];
  // }
  // ll sum[n] = {0};
  // for(i=0;i<neg.size();i++){
  //   int ind = neg[i].second;
  //   if(ss.size()==0){
  //     if(a[ind]+b[ind]>=0){
  //       ss.insert(ind);
  //       sum[ind] -= a[ind];
  //       b[ind] -= a[ind];
  //       ans++;
  //     }
  //   }
  //   else{
  //     auto it = upper_bound(ss.begin(),ss.end(), int);
  //     if(it == ss.begin()){
        
  //     }
  //     else{
        
  //     }
  //   }
  //   // int s = 0;
  //   // f[neg[i].second] = 1;
  //   // int flag=0;
  //   // for(j=0;j<n;j++){
  //   //   if(a[j]>0 or f[j] == 1)s+=a[j];
  //   //   if(s<0)flag = 1;
  //   // }
  //   // if(flag){
  //   //   f[neg[i].second] = 0;
  //   // }
  //   // else{
  //   //   ans++;
  //   // }
  // }
  // cout<<ans<<"\n";
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