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

void primeFactors(int n, int *f) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        f[2]++;
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            f[i]++; 
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        f[n]++;
} 


void solve(){
  ll n,i,j; cin>>n;
  //vector<int>v;
  j=n;
  //reverse(ss.begin(), ss.end()); 
  while(1){
    int k=n;
    //for(i=0;i<ss.length();i++)k+=power(10,i)*(ss[i]-48);
    vector<int>v;
    while(k){
      if(k%10)v.pb(k%10);
      k/=10;
    }
    k=n;
    int fff=0;
    for(i=0;i<v.size();i++){
      if(k%v[i]!=0){fff=1;break;}
    }
    if(fff)n++;
    else{cout<<n<<"\n";break;}
  }
  // set<int>s;
  // int f[11]={0};
  // int ans=1;
  // for(i=0;i<v.size();i++){
  //   // int ff[11]={0};
  //   // primeFactors(v[i],ff);
  //   // for(i=0;i<11;i++)f[i]=max(f[i],ff[i]);
  //   if(ans%v[i]==0)continue;
  //   ans*=(v[i]/gcd(v[i],ans));
  // }
  // //cout<<ans<<"\n";
  // if(n%ans==0)cout<<n<<"\n";
  // else if(ans>n)cout<<ans<<"\n";
  // else{
  //   ll k=n/ans;
  //   k++;
  //   ans*=k;
  //   cout<<ans<<"\n";
  // }
  //ll ans=1;
  // for(i=1;i<11;i++){
  //   ans*=(power(i,f[i]));
  // }
  // if(ans>=n)cout<<ans<<"\n";
  // else{
  //   cout<<ans<<"\n";
  //   ll k=n/ans;
  //   ans*=(k+1);
  //   cout<<ans<<"\n";
  // }
  return;
  //string s; cin>>s;
  // ll c=0;
  // for(i=n-1;i>=0;i--){
  //   if(s[i]==')')c++;
  //   else break;
  // }
  // for(;i>=0;i--){
  //   c--;
  // }
  // if(c<=0)cout<<"No\n";
  // else cout<<"Yes\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  fact[0]=1;
  for(int i=1;i<200001;i++){
    fact[i]=i*fact[i-1];
    fact[i]%=mod;
  }
  while (t--){
    solve();
  }
  return 0;
}