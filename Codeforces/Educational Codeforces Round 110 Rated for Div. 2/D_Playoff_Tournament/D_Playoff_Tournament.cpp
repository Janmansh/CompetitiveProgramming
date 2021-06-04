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
  if(y<0)return 0;
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
  int k;
  cin>>k;
  string s;
  cin>>s;
  int i,j,n = s.length();
  //s.pb('?');
  string t;
  t = " ";
  for(i=n-1;i>=0;i--)t.pb(s[i]);
  //cout<<t<<" ";
  //reverse(t.begin(),t.end());
  int arr[n+1]={0};
  //cout<<n<<"\n";
  // for(i=n;i>n/2;i--){
  //   if(t[i] == '?')arr[i] = 2;
  //   else t
  // }
  for(i=n;i>=1;i--){
    if(i<=n and i>n/2){
      if(t[i] == '?')arr[i] = 2;
      else arr[i] =1;
      continue;
    }
    arr[i]=0;
    int l = 0;
    int r = 0;
    //int co=0;
    if(2*i<=n)r=arr[2*i];
    if(2*i+1<=n)l=arr[2*i+1];
    //cout<<l<<" "<<r<<"\n";
    if(t[i] == '?')arr[i]=(l+r);
    else if(t[i]=='1')arr[i] = r;
    else arr[i] = l;
    //cout<<t[i]<<" "<<arr[i]<<" "<<i<<" \n";
  }
  //for(i=1;i<=n;i++)cout<<arr[i]<<" ";
  //cout<<"\n";
  int q;
  cin>>q;
  while(q--){
    int p; char c;
    cin>>p>>c;
    i = n-p+1;
    t[n-p+1]=c;
    int parent = i/2;
    int le = 0;
    int ri = 0;
    if(2*i+1<=n){
      le = arr[2*i+1];
      ri = arr[2*i];
      if(t[i]=='?')arr[i] = arr[2*i] + arr[2*i+1];
      else if(t[i]=='1')arr[i] = arr[2*i];
      else arr[i] = arr[2*i+1];
    }
    else{
      if(t[i] == '?')arr[i] = 2;
      else arr[i] = 1;
    }
    
    // if(q==1){
    // cout<<t<<"\n";
    // cout<<parent<<" "<<le<<" "<<ri<<" "<<arr[i]<<"\n";
    // }
    while(parent>0){
      if(t[parent] == '?'){
        arr[parent] = arr[2*parent]+arr[2*parent+1];
      }
      else if(t[parent] == '1'){
        arr[parent] = arr[2*parent];
      }
      else{
        arr[parent] = arr[2*parent+1];
      }
      parent/=2;
    }
    cout<<arr[1]<<"\n";
    //int q=0;
    // for(i=n-1;i>=max(0ll,n-3);i--){
    //   if(s[i]=='?')q++;
    // }
    //cout<<power(2ll,q-1)+1<<"\n";
  }
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