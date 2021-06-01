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
    // int i,j,x,y;
    // cin>>x>>y;
    // string s,s1;
    // cin>>s;
    // s1=s;
    // int n=s.length();
    // for(i=0;i<n;i++){
    //     if(s[i]=='J'||s[i]=='C')continue;
    //     for(j=i;j<n;j++){
    //         if(s[j]!='?')break;
    //     }
    //     char c = s[j];
    //     j--;
    //     for(;j>=i;j--)s[j]=c;
    // }
    // int ans=0;
    // for(i=0;i<n-1;i++){
    //     if(s[i]=='C'&&s[i+1]=='J')ans+=x;
    //     if(s[i]=='J'&&s[i+1]=='C')ans+=y;
    // }
    // cout<<ans<<"\n";
  int n,i,j,c,ans=0;
  cin>>n>>c;
  if(c<n-1 || c>=(n*(n+1))/2){
      cout<<"IMPOSSIBLE\n";return;
  }
  c-=n-1;
  int a[n];
  for(i=1;i<=n;i++){
      a[i-1]=i;
  }
  //int y=1;
  for(i=n;i>=0;i--){
    if(c==0)break;
      if(c>=(i-1)){
          //y-=1;
          int x = n-i;
          int st = x/2;
          int en = i+st;
          en--;
          //cout <<i<<" kk ";
          for(int z=st;z<st+(en-st+1)/2;z++){
            int temp = a[z];
            a[z] = a[en-z+st];
            a[en-z+st]=temp;
          }
          //y+=i;
          c-=(i-1);
      }
  }
  for(i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<"\n";
  //ll a[n];
  //for(i=0;i<n;i++)cin>>a[i];
//   for(i=0;i<n-1;i++){
//       int min = a[i];
//       j=i;
//       for(int z=i;z<n;z++){
//           if(a[z]<min){
//               min = a[z];
//               j=z;
//           }
//       }
//       ans+=j-i+1;
//       int b[j-i+1];
//       for(int z=i;z<i+(j-i+1)/2;z++){
//           int temp = a[z];
//           a[z] = a[j-z+i];
//           a[j-z+i]=temp;
//       }
//   }
//   cout<<ans<<"\n";
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
  int x=1;
  while (t--){
    cout << "Case #"<<x<<": ";
    x++;
    solve();
  }
  return 0;
}