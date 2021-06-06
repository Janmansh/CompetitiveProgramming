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
  ll fr[26]={0};
  cin>>s;
  for(i=0;i<n;i++)fr[s[i]-97]++;
  for(i=0;i<26;i++){
    if(fr[i]==0){
      char c = 97+i;
      cout<<c<<"\n";
      return;
    }
  }
  map<string,int>m;
  string ans = "aa";
  while(1){
    int f=1;
    for(i=0;i<=n-ans.length();i++){
      if(s[i]==ans[0]){
        int ff=1;
        int z=1;
        for(j=i+1;j<i+ans.length();j++){
          if(s[j]!=ans[z]){
            ff=0;break;
          }
          z++;
        }
        if(ff){
          f=0;
          break;
        }
      }
    }
    if(f){
      cout<<ans<<"\n";return;
    }
    if(ans[ans.length()-1]!='z'){
      int cc = ans[ans.length()-1];
      ans.pop_back();
      ans.pb(cc+1);
    }
    else{
      int x = ans.length()-1;
      while(x>=0 and ans[x]=='z'){
        ans[x]='a';
        x--;
      }
      if(x<0){
        ans.pb('a');
      }
      else{
        ans[x] = ans[x]+1;
      }
    }
  }
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