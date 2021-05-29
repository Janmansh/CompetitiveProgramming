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
  ll n,i,j; cin>>n;
  ll a[n];
  vector<pair<int,int>>v;
  for(i=0;i<n;i++){
    cin>>a[i];
    v.pb(mp(a[i],i));
  }
  sort(v.begin(),v.end());
  map<int,int>m;
  m[0]=n;
  m[1]=n;
  map<int,int>kk;
  for(i=0;i<v.size();i++){
    kk[v[i].second]=i;
  }
  ll x=n*a[0]+n*a[1];
  ll ans=x;
  ll min1;
  if(a[0]<=a[1])min1=0;
  else min1 = 1;
  ll min2 = 1-min1;
  ll ff[n]={0};
  ff[0]=n;
  ff[1]=n;
  ll mine=0,mino=1;
  ll o=1,e=1;
  for(i=2;i<n;i++){
    if(i%2==0){
      if(a[i]<a[mine]){
        x-=(ff[mine]*a[mine]);
        x+=(a[mine]);
        ff[i]=ff[mine]-1;
        x+=(ff[i]*a[i]);
        ff[mine]=1;
        mine = i;
      }
      else{
        ff[i]=min(1ll,ff[mine]-1);
        ff[mine]-=ff[i];
        x-=a[mine]*ff[i];
        x+=a[i]*ff[i];
      }
    }
    else{
      if(a[i]<a[mino]){
        x-=(ff[mino]*a[mino]);
        x+=(a[mino]);
        ff[i]=ff[mino]-1;
        x+=(ff[i]*a[i]);
        ff[mino]=1;
        mino = i;
      }
      else{
        ff[i]=min(1ll,ff[mino]-1);
        ff[mino]-=ff[i];
        x-=a[mino]*ff[i];
        x+=a[i]*ff[i];
      }
    }
    
    // if(a[i]<a[min1]){
    //   if(min2!=-1){
    //     x-=(ff[min2]*a[min2]);
    //     x+=a[min2];
    //     ff[i]=ff[min2]-1;
    //     ff[min2]=1;
    //     int d = min(n-ff[i], ff[min1]-1);
    //     ff[i]+=d;
    //     x-=(ff[min1]*a[min1]);
    //     ff[min1]-=d;
    //     x+=(ff[min1]*a[min1]);
    //     min1=i;
    //     x+=(ff[i]*a[i]);
    //   }
    //   else{
    //     int d = min(n-ff[i], ff[min1]-1);
    //     ff[i]+=d;
    //     x-=(ff[min1]*a[min1]);
    //     ff[min1]-=d;
    //     x+=(ff[min1]*a[min1]);
    //     min1=i;
    //     x+=(ff[i]*a[i]);
    //   }
    // }
    // else if(a[i]>=a[min1]){
    //   if(min2==-1){
    //     x-=a[min1];
    //     ff[min1]--;
    //     x+=a[i];
    //     ff[i]=1;
    //   }
    //   else{
    //     if(a[i]>=a[min2]&&ff[min2]>1){
    //       x-=a[min2];
    //       ff[min2]--;
    //       x+=a[i];
    //       ff[i]=1;
    //     }
    //     else if(a[i]>=a[min2]){
    //       x-=a[min1];
    //       ff[min1]--;
    //       //x-=(ff[min2]*a[min2]);
    //       x+=a[i];
    //       ff[i]=1;
    //     }
    //     else{
    //       if(ff[min2]>1){
    //         x-=(ff[min2]*a[min2]);
    //         x+=a[min2];
    //         ff[i]=ff[min2]-1;
    //         ff[min2]=1;
    //         min2=i;
    //         x+=(ff[i]*a[i]);
    //       }
    //       else{
    //         x-=a[min1];
    //         ff[min1]--;
    //         //x-=(ff[min2]*a[min2]);
    //         x+=a[i];
    //         ff[i]=1;
    //       }
    //     }
    //   }
    // }
    ans=min(x,ans);
    //if(ff[i]==0)break;
  }
  //for(i=0;i<n;i++)cout<<ff[i]<<" ";
  cout<<ans<<"\n";
  // string s; cin>>s; 
  // ll n,i,j; n=s.length();
  // int f=0,f1=0;
  // for(i=0;i<n-1;i++){
  //   if(s[i]=='1'&&s[i+1]=='1'){
  //     f=1;
  //     break;
  //   }
  // }
  // i++;
  // for(;i<n-1;i++){
  //   if(s[i]=='0'&&s[i+1]=='0'){
  //     f1=1;
  //     break;
  //   }
  // }
  // if(f&&f1){
  //   cout<<"NO\n";
  // }
  // else{
  //   cout<<"YES\n";
  // }
  // ll i,j,n,k1,k2; cin>>n>>k1>>k2;
  // ll temp = min(k1,k2);
  // ll w,b; cin>>w>>b;
  // if(w+b!=n){
  //   cout<<"NO\n";return;
  // }
  // ll t = max(k1,k2);
  // k1 = temp;
  // k2= t;
  // if((k1+k2)%2==0 &&(k1+k2)/2 == w && (n+n-(k1+k2))%2==0 && ((2*n-(k1+k2))/2)==b){
  //   cout<<"YES\n";
  // }
  // else{
  //   cout<<"NO\n";return;
  // }
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