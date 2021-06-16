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
 
ll nCr(ll n, ll r){
	if(r > n) return 0;
	ll t1 = fact[n];
	ll t2 = fact[r];
	ll t3 = fact[n-r];
 
	return (t1/(t2*t3));
}

bool boo(pair<int,string>a,pair<int,string>b){
  return(a.first>=b.first);
}


void solve(){
  ll n,i,j;
  string s;
  cin>>s;
  ll o=0,x=0;
  for(i=0;i<10;i++){
    if(s[i]=='o')o++;
    else if(s[i]=='x')x++;
  }
  if(o>4){
    cout<<"0\n";return;
  }
  x=10-(o+x);
  ll ans=0;
  j=0;
  while(o+j<=4 && j<=x){
    ll t=o+j;
    for(i=t;i>=0;i--){
      if(i%2==0)ans+=((nCr(t,t-i)*power(t-i,4ll))*nCr(x,j));
      else ans-=((nCr(t,t-i)*power(t-i,4ll))*nCr(x,j));
    }
    //ans+=((fact[4]/(fact[o+j]*fact[4-(o+j)]))*(fact[x]/(fact[x-j]*fact[j]))*power(o+j,4-(o+j))*fact[o+j]);
    j++;
  }
  //ans+=((fact[x])/(fact[x-4+o]*fact[4-o]));
  //ans*=24;
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  //srand(time(0));
  fact[0]=1;
  for(int i=1;i<=10;i++){
    fact[i]=i*fact[i-1];
  }
  while (t--){
    solve();
  }
  return 0;
}