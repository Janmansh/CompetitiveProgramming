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
  for(i=0;i<n;i++)cin>>a[i];
  if(n<=2){
    cout<<"Yes\n";return;
  }
  int ma = max(a[0],a[1]);
  int mi = min(a[0],a[1]);
  set<int>s;
  s.insert(a[0]);
  int last=a[0];
  //if(a[1]<a[0])
  for(i=1;i<n;i++){
    if(a[i] == last)continue;
    if(s.find(a[i])==s.end()){
      s.insert(a[i]);
    }
    // if(s.size()<2){
    //   s.insert(a[i]);
    //   continue;
    // }
    // if(a[i]<mi and mi!=INT_MAX){
    //   cout<<"No\n";return;
    // }
    // mi = min(mi,a[i]);
    // ma = max(ma,a[i]);
    auto it1 = s.find(last);
    if(it1!=s.begin()){
      auto it2 = it1;
      it2--;
      mi = *it2;
    }
    else{
      mi = INT_MIN;
    }
    auto it3 = it1;
    it3++;
    if(it3!=s.end()){
      ma = (*it3);
    }
    else{
      ma = INT_MAX;
    }
    if(a[i]==ma or a[i]==mi){
      //cout<<a[i]<<" ";
      //cout<<(*it1)<<" "<<mi<<"\n";
      last = a[i];
    }
    else{
      //s.insert(a[i]);
      //last = a[i];
      cout<<"No\n";return;
    }
  }
  cout<<"Yes\n";
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