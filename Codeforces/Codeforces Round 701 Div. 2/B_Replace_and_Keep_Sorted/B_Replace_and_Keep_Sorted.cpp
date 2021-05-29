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
  ll n,i,j,q,k; cin>>n>>q>>k;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll f[n+1]={0};
  f[0]=0;
  for(i=0;i<n;i++){
    if(i!=0){
      f[i+1]=a[i]-a[i-1]-1;
    }
    if(i!=n-1){
      f[i+1]+=a[i+1]-a[i]-1;
    }
  }
  //for(i=0;i<=n;i++)cout<<f[i]<<" ";
  ll pre[n+1]={0},pos[n+1]={0};
  for(i=0;i<n;i++){
    pre[i+1]=a[i]-1;
    pos[i+1]=k-a[i];
  }
  for(i=1;i<=n;i++){
    f[i]+=f[i-1];
  }
  //for(i=0;i<=n;i++)cout<<f[i]<<" ";
  ll l,r;
  while(q--){
    cin>>l>>r;
    ll ans=0;
    ans+=pre[l];
    ans+=pos[r];
    ans+=(f[r]-f[l-1]);
    if(r!=n){
      ans-=(a[r]-a[r-1]-1);
    }
    if(l!=1){
      ans-=(a[l-1]-a[l-2]-1);
    }
    cout<<ans<<"\n";
  }
  
  // ll a,b;
  // cin>>a>>b;
  // int x=a,ans=1000000007;
  // int k=0;
  // while(1){
  //   x=a;
  //   int c=k;
  //   if(b==1){c++;b++;k++;}
  //   while(x){
  //     c++;
  //     x/=b;
  //   }
  //   //cout<<b<<" ";
  //   if(c<=ans)ans=c;
  //   else break;
  //   b++;
  //   k++;
  // }
  // cout<<ans<<"\n";
  return;
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
    //cout<<t<<" ";
    solve();
  }
  return 0;
}