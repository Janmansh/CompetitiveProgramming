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
  ll n,k,i,j;
  cin>>n>>k;
  string s;
  cin>>s;
  set<string>s1;
  for(i=0;i<n;i++){
    string temp = s.substr(0,i+1);
    string ans = "";
    int x = k/(i+1);
    int y = k%(i+1);
    for(j=0;j<x;j++)ans.append(temp);
    for(j=0;j<y;j++)ans.pb(s[j]);
    s1.insert(ans);
  }
  auto it = s1.begin();
  string answer = (*it);
  cout<<answer<<"\n";
  // j=-1;
  // for(i=1;i<n;i++){
  //   if(s[i]>s[0]){
  //     j = i;
  //     break;
  //   }
  //   if(s[i]==s[0]){
  //     string temp = s.substr(0,i);
  //     string temp1 = s.substr(i,min(i,n-i));
  //     if(temp<=temp1){
  //       j=i;
  //       break;
  //     }
  //   }
  // }
  // //cout<<j<<" ";
  // if(j==-1){
  //   int x = k/n;
  //   k-=(x*n);
  //   for(i=0;i<x;i++)cout<<s;
  //   for(i=0;i<k;i++)cout<<s[i];
  //   return;
  // }
  // // char top = s[n-1];
  // // i = n-1;
  // // while(i>0 and top>s[0]){
  // //   i--;
  // //   top = s[i];
  // // }
  // // string t = "";
  // // for(j=0;j<=i;j++)t.pb(s[j]);
  // int xx = k/(j);
  // k-=(xx*j);
  // for(int z = 0;z<xx;z++){
  //   for(i=0;i<j;i++)cout<<s[i];
  // }
  // for(i=0;i<k;i++){
  //   cout<<s[i];
  // }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
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