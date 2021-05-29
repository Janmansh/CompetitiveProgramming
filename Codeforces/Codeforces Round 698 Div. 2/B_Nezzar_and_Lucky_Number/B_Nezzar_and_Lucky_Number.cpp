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
  ll n,m,i,j,d;cin>>n>>d;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll f[d]={0};
  map<int,string>mm;
  for(i=1;i<(d*10);i++){
      //cout<<"lala";
      ll kk=i%10;
      ll dd = i%d;
      //cout<<i;
      if(kk==d){
          f[dd]=1;
          //cout<<"k";
      }
      if(f[dd]==1){
          mm[i]="YES";
      }
      else if(f[dd]==0){
          mm[i]="NO";
      }
  }
  for(j=0;j<n;j++){
      if(a[j]>=d*10){
          cout<<"YES\n";
      }
      else{
          cout<<mm[a[j]]<<"\n";
      }
  }
  
  //ll ans=1;
  //for(i=0;i<=n;i++)ans=max(ans,f[i]);
  //cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
   fact[0]=1;
   for(int i=1;i<200001;i++){
     fact[i]=i*fact[i-1];
     fact[i]%=mod;
   }
  while (t--){
    solve();
  }
  return 0;
}