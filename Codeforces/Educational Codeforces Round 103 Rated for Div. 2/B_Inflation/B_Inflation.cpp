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
    ll n,k,i,j; cin>>n>>k;
    ll a[n];
    for(i=0;i<n;i++)cin>>a[i];
    ll s=a[0],ans=0;
    // for(i=1;i<n;i++){
    //     if(100*a[i]>s*k){
    //         ans+=a[i]*100-k*s;
    //         a[i]+=(a[i]*100-k*s);
    //     }
    //     s+=a[i];
    // }
    int low=0,high=1000000000000,mid;
    while(low<high){
        mid = low + (high-low)/2;
        //if(mid<200)cout<<low<<" "<<mid<<" "<<high<<" ";
        s=mid+a[0];
        int f=0;
        for(i=1;i<n;i++){
            if(a[i]*100>s*k){
                f=1;
                break;
            }
            s+=a[i];
        }
        if(f)low=mid+1;
        else{
            high=mid;
            ans=mid;
        }
    }
    //ll ans=k/n;
    //if(ans==0&&n%k!=0)ans++;
    //if(k%n)ans++;
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
  while (t--){
    solve();
  }
  return 0;
}