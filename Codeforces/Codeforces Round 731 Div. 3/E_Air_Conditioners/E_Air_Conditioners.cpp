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
  ll n,i,j,k,m;
  cin>>n>>k;
  ll a[k], t[k];
  ll ans[n];
  for(i=0;i<k;i++)cin>>a[i];
  vector<pair<int,int>>v;
  for(i=0;i<n;i++)ans[i] = INT_MAX;
  for(i=0;i<k;i++){
    cin>>t[i];
    ans[a[i]-1]=t[i];
    v.pb(mp(t[i],a[i]-1));
  }
  sort(v.begin(),v.end());
  for(i=0;i<k;i++){
    ll tem=v[i].first;
    ll ind=v[i].second;
    ll k=0;
    for (j=ind;j>=0;j--){
      if (tem+k<=ans[j]){
        ans[j]=tem+k;
        k++;
      }
      else break;
    }
    k=1;
    for(j=ind+1;j<n;j++){
      if(tem+k<ans[j]){
        ans[j]=tem+k;
        k++;
      }
      else break;
    }
  }
  // vector<int>v1;
  // v1.pb(0);
  // for(i=1;i<k;i++){
  //   while(!v1.empty() and v[i].second+(abs(v[i].first-v[v1.back()].first))<=v[v1.back()].second){
  //     v1.pop_back();
  //   }
  //   v1.pb(i);
  // }
  // // for(i=0;i<v1.size();i++)cout<<v[v1[i]].first<<" ";
  // // cout<<"\n";
  // ll ans[n];
  // for(i=0;i<v[v1[0]].first;i++){
  //   ans[i] = v[v1[0]].second+v[v1[0]].first-i-1;
  // }
  // j=1;
  // for(;i<n;){
  //   if(j==v1.size()){
  //     ans[i] = v[v1[j-1]].second+abs(v[v1[j-1]].first-i-1);
  //     i++;
  //   }
  //   else{
  //     for(;i<v[v1[j]].first;i++){
  //       ans[i] = min(v[v1[j-1]].second+abs(v[v1[j-1]].first-i-1),v[v1[j]].second+abs(v[v1[j]].first-i-1));
  //     }
  //     j++;
  //   }
  // }
  // v1.clear();
  // v1.pb(k-1);
  // for(i=k-2;i>=0;i--){
  //   while(!v1.empty() and v[i].second+(abs(v[i].first-v[v1.back()].first))<=v[v1.back()].second){
  //     v1.pop_back();
  //   }
  //   v1.pb(i);
  // }
  // for(i=n-1;i>=v[v1[0]].first;i--){
  //   ans[i] = min(ans[i],v[v1.back()].second+abs(v[v1.back()].first-i-1));
  // }
  // j=1;
  // for(;i>=0;){
  //   if(j==v1.size()){
  //     ans[i] = min(ans[i], v[v1[j-1]].second+abs(v[v1[j-1]].first-i-1));
  //     i--;
  //   }
  //   else{
  //     for(;i>=v[v1[j]].first;i--){
  //       ans[i] = min({ans[i], v[v1[j-1]].second+abs(v[v1[j-1]].first-i-1),v[v1[j]].second+abs(v[v1[j]].first-i-1)});
  //     }
  //     j++;
  //   }
  // }
  for(i=0;i<n;i++)cout<<ans[i]<<" ";
  cout<<"\n";
  // // int mi = INT_MAX, ind = -1;
  // // for(i=0;i<k;i++){
  // //   int tem = v[i].second+v[i].first - 1;
  // //   if(tem<mi){
  // //     mi = tem;
  // //     ind = v[i].first-1;
  // //   }
  // // }
  // // for(i=0;)
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