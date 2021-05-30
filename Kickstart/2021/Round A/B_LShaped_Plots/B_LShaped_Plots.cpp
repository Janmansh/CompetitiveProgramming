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
    ll i, j, r, c;
    cin>>r>>c;
    ll a[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)cin>>a[i][j];
    }
    ll rowr[r][c],cold[r][c],rowl[r][c],colu[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            rowr[i][j]=a[i][j];
            cold[i][j]=a[i][j];
            rowl[i][j]=a[i][j];
            colu[i][j]=a[i][j];
        }
    }
    for(i=0;i<r;i++){
        for(j=1;j<c;j++){
            if(a[i][j]==1)rowr[i][j]+=rowr[i][j-1];
        }
    }
    for(i=0;i<r;i++){
        for(j=c-2;j>=0;j--){
            if(a[i][j]==1)rowl[i][j]+=rowl[i][j+1];
        }
    }
    for(j=0;j<c;j++){
        for(i=1;i<r;i++){
            if(a[i][j]==1)cold[i][j]+=cold[i-1][j];
        }
    }
    for(j=0;j<c;j++){
        for(i=r-2;i>=0;i--){
            if(a[i][j]==1)colu[i][j]+=colu[i+1][j];
        }
    }
    ll ans=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(rowr[i][j]>1){
                ans+=(min(max(0ll,colu[i][j]/2-1), rowr[i][j]-1)+min(rowr[i][j]/2-1,max(0ll,colu[i][j]-1))+min(max(0ll,cold[i][j]/2-1), rowr[i][j]-1)+min(rowr[i][j]/2-1,max(0ll,cold[i][j]-1)));
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(rowl[i][j]>1){
                ans+=(min(max(0ll,colu[i][j]/2-1), rowl[i][j]-1)+min(rowl[i][j]/2-1,max(0ll,colu[i][j]-1))+min(max(0ll,cold[i][j]/2-1), rowl[i][j]-1)+min(rowl[i][j]/2-1,max(0ll,cold[i][j]-1)));
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