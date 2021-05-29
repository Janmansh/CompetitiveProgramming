#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define double long double

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
  ll n,i,j;string s; cin>>s;
  n=s.length();
  set<pair<int,int>>p;
  ll xx=0,yy=0;
  for(i=0;i<n;i++){
    if(s[i]=='L'){xx--;}
    if(s[i]=='U'){yy++;}
    if(s[i]=='R'){xx++;}
    if(s[i]=='D'){yy--;}
    p.insert(mp(xx,yy));
  }
  i=0;
  vector<pair<int,int>>v;
  for(auto it=p.begin();it!=p.end();++it){
    v.pb(*it);
  }
  for(i=0;i<v.size();i++){
    ll x=v[i].first,y=v[i].second,x1=0,y1=0;
    ll r=0,d=0;
    for(j=0;j<n;j++){
      if(s[j]=='L'){
        if((x1-1)==x&&y1==y)continue;
        r--;
        x1--;
      }
      if(s[j]=='U'){
        if(x1==x&&y1==(y-1))continue;
        d--;
        y1++;
      }
      if(s[j]=='R'){
        if((x1+1)==x&&y1==y)continue;
        r++;
        x1++;
      }
      if(s[j]=='D'){
        if(x1==x&&y1==(y+1))continue;
        d++;
        y1--;
      }
    }
    if(r==0&&d==0){
      cout<<x<<" "<<y<<"\n";return;
    }
  }
  cout<<"0 0\n";
  // for(i=0;i<n;i++){
  //   ll x=0,y=0;
  //   ll l=0,r=0,u=0,d=0;
  //   for(j=0;j<i;j++){
  //     if(s[j]=='L'){l++;x--;}
  //     if(s[j]=='U'){u++;y++;}
  //     if(s[j]=='R'){l--;x++;}
  //     if(s[j]=='D'){u--;y--;}
  //   } 
  //   ll x1=x,y1=y;
  //   //ll l1=0,r1=0,u1=0,d1=0;
  //   if(s[i]=='L'){x--;}
  //   if(s[i]=='U'){y++;}
  //   if(s[i]=='R'){x++;}
  //   if(s[i]=='D'){y--;}//++;}
  //   for(j=i+1;j<n;j++){
  //     if(s[j]=='L'){
  //       if((x1-1)==x&&y1==y)continue;
  //       r--;
  //       x1--;
  //     }
  //     if(s[j]=='U'){
  //       if(x1==x&&y1==(y-1))continue;
  //       d--;
  //       y1++;
  //     }
  //     if(s[j]=='R'){
  //       if((x1+1)==x&&y1==y)continue;
  //       r++;
  //       x1++;
  //     }
  //     if(s[j]=='D'){
  //       if(x1==x&&y1==(y+1))continue;
  //       d++;
  //       y1--;
  //     }
  //   }
    
  //   if(l==r&&u==d){
  //     cout<<x<<" "<<y<<"\n";
  //     return;
  //   }
  // }
  return;
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