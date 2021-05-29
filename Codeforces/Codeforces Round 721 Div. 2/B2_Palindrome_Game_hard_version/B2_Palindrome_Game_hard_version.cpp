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
  ll n,i,j;
  cin>>n;
  string s;
  cin>>s;
  int k=0;
  int l=0,h=s.size()-1;
  while(l<h){
    if(s[l++]!=s[h--]){
      k++;
    }
  }
  if(k>=2){
    cout<<"ALICE\n";return;
  }
  if(k==0){
    int c=0;
    for(i=0;i<n;i++){
      if(s[i]=='0')c++;
    }
    if(c==0){
      cout<<"DRAW\n";return;
    }
    if(c==1){
      cout<<"BOB\n";return;
    }
    if(c%2){
      cout<<"ALICE\n";return;
    }
    cout<<"BOB\n";
    return;
  }
  // if(k==2){
  //   // k=0;
  //   // for(i=0;i<n;i++)if(s[i]=='0')k++;
  //   // k-=2;
  //   // if(k%2){
  //   //   cout<<"ALICE\n";return;
  //   // }
  //   // if(k>=2){
  //   //   cout<<"DRAW\n";return;
  //   // }
  //   cout<<"ALICE\n";return;
  // }
  k=0;
  for(i=0;i<n;i++){
    if(s[i]=='0')k++;
  }
  k--;
  if(k==0){
      cout<<"ALICE\n";return;
  }
  if(k==1){
      cout<<"DRAW\n";return;
  }
  //if(k%2){
      cout<<"ALICE\n";return;
  //}
  //cout<<"BOB\n";
  return;
  // if(n==1){
  //   cout<<"0\n";return;
  // }
  // ll p[32];
  // p[0]=1;
  // for(i=1;i<32;i++)p[i]=p[i-1]*2;
  // for(i=0;i<32;i++){
  //   if(p[i]>n)break;
  // }
  // i--;
  // cout<<p[i]-1<<"\n";
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