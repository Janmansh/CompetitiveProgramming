#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define double long double

//vector<vector<int>>adj(100005);
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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

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


void solve(){
  ll i,j,n;
  cin>>n;
  ll x[n];
  for(i=0;i<n;i++)cin>>x[i];
  ll u,vi;
  map<int,int>mm;
  for(i=0;i<n-1;i++){
    cin>>u>>vi;
    mm[u]++;mm[vi]++;//.pb(vi);adj[vi].pb(u);
  }
  vector<pair<int,int>>v;
  for(i=1;i<=n;i++){
    int k=mm[i];
    v.pb(mp(x[i-1],k));
  }
  sort(v.begin(),v.end());
  //for(i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second;
  ll s=0;
  ll sum[n-1];
  for(i=0;i<n-1;i++)sum[i]=0;
  j=v.size()-1;
  i=0;
  int l=0;
  // for(i=v.size()-1;i>=0;i--){
  //   if(v[i].second<=1)continue;
  //   sum[l]=v[i].first;
  //   l+=(v[i].second-1);
  //   // for(j=0;j<v[i].second-1;j++){
  //   //   sum[l]=v[i].first;
  //   //   l++;
  //   // }
  // }
  for(i=1;i<=n;i++){
    if(sum[i]==0)sum[i]=sum[i-1];
  }
  //for(i=0;i<n;i++)cout<<sum[i]<<" ";
    // v[j].second-=1;
    // if(v[j].second>=1)sum[i]=v[j].first;
    // else{i--;j--;}
    // if(j<0)break;
  //}
  // while(){
  //   if(v[j].second==1){j--;continue;}
  //   sum[i]=v[j].first;
  //   v[j].second-=1;
  //   if(v[j].second==1)j--;
  //   i++;
  // }
  for(i=0;i<n;i++)s+=x[i];
  //cout<<s<<" ";
  ll last=n-1;
  for(i=0;i<n-1;i++){
    cout<<s<<" ";
    if(last==-1)continue;
    //if(v[last].second>1)s+=v[last].first;
    if(v[last].second<=1){
      while(last>=0&&v[last].second<=1){
        last--;
      }
    }
    if(last==-1)continue;
    //else{s+=v[last].first;v[last].second--;}
    s+=v[last].first;v[last].second--;
  }
  cout<<"\n";
  //for(i=0;i<=100000;i++)adj[i].clear();
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  //fact[0]=1;
  //for(int i=1;i<200001;i++){
    //fact[i]=i*fact[i-1];
    //fact[i]%=mod;
  //}
  while (t--){
    solve();
  }
  return 0;
}