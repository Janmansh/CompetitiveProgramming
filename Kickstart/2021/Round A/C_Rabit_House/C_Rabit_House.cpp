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
    int i,j,r,c;
    cin>>r>>c;
    ll a[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(int z=0;z<300;z++){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(j!=c-1){
                if(abs(a[i][j]-a[i][j+1])>1){
                    if(a[i][j]>a[i][j+1]){
                        ans+=a[i][j]-a[i][j+1]-1;
                        a[i][j+1]=a[i][j]-1;
                    }
                    else{
                        ans+=a[i][j+1]-a[i][j]-1;
                        a[i][j]=a[i][j+1]-1;
                    }
                }}
                if(j!=0){
                if(abs(a[i][j]-a[i][j-1])>1){
                    if(a[i][j]>a[i][j-1]){
                        ans+=a[i][j]-a[i][j-1]-1;
                        a[i][j-1]=a[i][j]-1;
                    }
                    else{
                        ans+=a[i][j-1]-a[i][j]-1;
                        a[i][j]=a[i][j-1]-1;
                    }
                }}
                if(i!=0){
                if(abs(a[i][j]-a[i-1][j])>1){
                    if(a[i][j]>a[i-1][j]){
                        ans+=a[i][j]-a[i-1][j]-1;
                        a[i-1][j]=a[i][j]-1;
                    }
                    else{
                        ans+=a[i-1][j]-a[i][j]-1;
                        a[i-1][j]=a[i][j]-1;
                    }
                }}
                if(i!=r-1){
                if(abs(a[i][j]-a[i+1][j])>1){
                    if(a[i][j]>a[i+1][j]){
                        ans+=a[i][j]-a[i+1][j]-1;
                        a[i+1][j]=a[i][j]-1;
                    }
                    else{
                        ans+=a[i+1][j]-a[i][j]-1;
                        a[i][j]=a[i+1][j]-1;
                    }
                }}
            }
        }
    }
    cout<<ans<<"\n";
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
  ll x=1;
  while (t--){
      cout<<"Case #"<<x<<": ";
      x++;
    solve();
  }
  return 0;
}