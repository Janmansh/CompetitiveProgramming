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
void solve() {
  ll i,j,n;
  cin>>n;
  int k = n*n;
  //int a[n][n];
  i=0,j=0;
  int a;
  //cin>>a;
  //a[i][j]=(a+1)%3;
  //cout<<(a+1)%3<<" "<<i+1<<" "<<j+1<<"\n";
  //cout.flush();
  vector<pair<int,int>>od,ev;
  int z;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if((i+j)%2){
        od.pb(mp(i,j));
      }
      else{
        ev.pb(mp(i,j));
      }
    }
  }
  // for(z=k-1;z>=0;z--){
  //   if(z%2){
  //     od.pb(z);
  //   }
  //   else{
  //     ev.pb(z);
  //   }
  // }
  for(z=0;z<k;z++){
    cin>>a;
    if(a!=3){
      if(od.size()!=0){
        int l = od[od.size()-1].first;
        int p = od[od.size()-1].second;
        cout<<"3 "<<l<<" "<<p<<"\n";
        cout.flush();
        od.pop_back();
      }
      else{
        int l = ev[ev.size()-1].first;
        int p = ev[ev.size()-1].second;
        cout<<3 - a << " " <<l<<" "<<p<<"\n";
        cout.flush();
        ev.pop_back();
      }
    }
    else if(a!=2){
      if(ev.size()!=0){
        int l = ev[ev.size()-1].first;
        int p = ev[ev.size()-1].second;
        cout<<"2 "<<l<<" "<<p<<"\n";
        cout.flush();
        ev.pop_back();
      }
      else{
        int l = od[od.size()-1].first;
        int p = od[od.size()-1].second;
        cout<<4 - a << " " <<l<<" "<<p<<"\n";
        cout.flush();
        od.pop_back();
      }
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
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