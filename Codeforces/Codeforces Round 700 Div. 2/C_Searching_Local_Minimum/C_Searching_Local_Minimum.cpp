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
  ll n,i,j,A,B; cin>>n;
  ll x,y,z;
  int low=1,high=n;
  ll ans[100001]={0};
  while(low<=high){
    x=1000000000;y=0;z=1000000000;
    int mid = (low+high)/2;
    // if(mid==1||mid==n){
    //   cout<<"! "<<mid<<"\n";
    //   return;
    // }
    if(ans[mid]==0){cout<<"? "<<mid<<"\n";cout.flush();
    cin>>y;ans[mid]=y;}
    else{
      y=ans[mid];
    }
    if(mid+1<=n){
      if(ans[mid+1]==0){cout<<"? "<<mid+1<<"\n";cout.flush();
    cin>>z;ans[mid+1]=z;}
    else{
      z=ans[mid+1];
    }
      //cout<<"? "<<mid+1<<"\n";
    //cout.flush();
    //cin>>z;
    }
    if(mid-1>=1){
      if(ans[mid-1]==0){cout<<"? "<<mid-1<<"\n";cout.flush();
    cin>>x;ans[mid-1]=x;}
    else{
      x=ans[mid-1];
    }
      //cout<<"? "<<mid-1<<"\n";
    //cout.flush();
    //cin>>x;
    }
    if(x>y&&y<z){
      cout<<"! "<<mid<<"\n";
      cout.flush();
      break;
      return;
    }
    if(x>y&&y>z){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
  //for(i=0;i<6;i++)cout<<ans[i]<<" ";
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