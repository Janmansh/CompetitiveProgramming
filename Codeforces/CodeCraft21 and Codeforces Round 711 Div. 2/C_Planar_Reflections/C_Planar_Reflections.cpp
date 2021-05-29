#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

//set<int>s;

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
    ll n,i,j,k; cin>>n>>k;
    ll a[k][n];
    for(i=0;i<k;i++){
      for(j=0;j<n;j++)a[i][j]=0;
    }
    if(k==1){
      cout<<"1\n";return;
    }
    if(n==1){
      cout<<"2\n";return;
    }
    for(i=0;i<n;i++){
      a[0][i]=1;
    }
    for(i=1;i<k;i++){
      for(j=n-2;j>=0;j--){
        a[i][j]=a[i][j+1]+a[i-1][j+1];
        a[i][j]%=mod;
      }
      i++;
      if(i>=k)break;
      for(j=1;j<n;j++){
        a[i][j] = a[i][j-1] + a[i-1][j-1];
        a[i][j]%=mod;
      }
    }
    ll ans=1;
    for(i=0;i<k-1;i++){
      for(j=0;j<n;j++){
        ans+=a[i][j];
        ans%=mod;
      }
    }
    cout<<ans<<"\n";
    // ll a[n];
    // for(i=0;i<n;i++)cin>>a[i];
    // sort(a,a+n);
    // //multiset<int>s;
    // int c=1;
    // s.insert(w);
    // //int s=0;
    // map<int,int>mm;
    // for(i=n-1;i>=0;i--){
    //   // if(s+a[i]<=w){
    //   //   s+=a[i];
    //   // }
    //   // else{
        
    //   // }
    //   auto it = lower_bound(s.begin(),s.end(),a[i]);
    //   if(it!=s.end()){
    //     int kk = *it;
    //     mm[kk]--;
    //     if(mm[kk]<=0) s.erase(it);
    //     s.insert(kk-a[i]);
    //     mm[kk-a[i]]++;
    //   }
    //   else{
    //     c++;
    //     s.insert(w-a[i]);
    //     mm[w-a[i]]++;
    //   }
    // }
    // cout<<c<<"\n";
    // s.clear();
    return;
    //ll p[32];
    //p[0]=1;
    //for(i=1;i<32;i++)p[i]=p[i-1]*2;
    //ll f[32];
    // for(i=n;i<=n+1000;i++){
    //   int x=0,t=i;
    //   while(t){
    //     x+=t%10;
    //     t/=10;
    //   }
    //   if(gcd(x,i)>1){
    //     cout<<i<<"\n";return;
    //   }
    // }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
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