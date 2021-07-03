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

int flag = 0, co=0;

void s(int n, int a, int b){
  co++;
  if(co>100)return;
  if(n==1 or flag){
    flag = 1;
    return;
  }
  if(n<1)return;
  if(n%a==0){
    s(n/a, a, b);
  }
  if((n-1)%b==0){
    flag = 1;
    return;
  }
  s(n-b, a, b);
}


void solve(){
  ll n,i,j,a,b;
  cin>>n>>a>>b;
  if(b==1){
    cout<<"Yes\n";return;
  }
  if(a==1){
    if((n-1)%b==0)cout<<"Yes\n";
    else cout<<"No\n";
    return;
  }
  if(n==1){
    cout<<"Yes\n";return;
  }
  int s=1;
  i=0;
  while(1){
    //s = power(a,i);
    if((n-s)%b==0){
      cout<<"Yes\n";return;
    }
    s*=a;
    if(n<s)break;
  }
  cout<<"No\n";return;
  // while(n>1){
  //   if((n-1)%b==0){
  //     cout<<"Yes\n";return;
  //   }
  //   if(n%a==0)n/=a;
  //   else{
  //     if((n-1)%b==0){
  //       cout<<"Yes\n";return;
  //     }
  //     if(n%g){
  //       cout<<"No\n";return;
  //     }
  //     n-=b;
  //     // int x = n/a;
  //     // int t = x*a;
  //     // if((n-t)%b==0){
  //     //   n = t;
  //     // }
  //     // else{
  //     //   cout<<"kNo\n";return;
  //     // }
  //   }
  // }
  // if(n==1)cout<<"Yes\n";
  // else cout<<"No\n";
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