#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007

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


void solve(){
  ll n,i,j=0,k;cin>>n>>k; ll a[n];string s;
  cin>>s;
  string l,p;
  l=s;p=s;
  ll t=0,m=0,k1=k,f=0,c=0;
  if(s[0]=='W')t++;
  for(i=1;i<n;i++){
    if(s[i-1]=='W'&&s[i]=='W')t+=2;
    else if(s[i]=='W')t++;
  }
  vector<ll>v;
  for(i=0;i<n;i++){
    if(k==0)break;
    if(s[i]=='W'&&s[i+1]=='L'&&f==0){
      c=0;
      f=1;continue;
    }
    if(s[i]=='L'&&f==1){
      c++;continue;
    }
    if(s[i]=='W'&&f==1){
      f=0;
      if(s[i+1]=='L')f=1;
      if(c<=k){
        v.pb(c);
        c=0;
      }
      else{
        c=0;
        continue;
      }
    }
    if(k==0)break;
  }
  if(k==0){
    cout<<t<<"\n";return;
  }
  if(t==0&&k!=0){
    cout<<2*k-1<<"\n";
    return;
  }
  sort(v.begin(),v.end());
  for(i=0;i<v.size();i++){
    if(v[i]<=k){
      t+=(2*v[i]+1);
      k-=v[i];
    }
  }
  t+=(2*k);
  t=min(2*n-1,t);
  cout<<t<<"\n";
  return;
  // for(i=1;i<n;i++){
  //   if(s[i-1]=='W'&&s[i]=='L'&&k>0){
  //     s[i]='W';k--;
  //   }
  // }
  // for(i=0;i<n;i++){
  //   if(s[i]=='L'&&k>0){
  //     s[i]='W';k--;
  //   }
  // }
  // if(s[0]=='W')j++;
  // for(i=1;i<n;i++){
  //   if(s[i-1]=='W'&&s[i]=='W')j+=2;
  //   else if(s[i]=='W')j++;
  // }
  // for(i=n-1;i>=0;i--){
  //   if(l[i]=='L'&&k1>0){l[i]='W';k1--;}
  // }
  // if(l[0]=='W')t++;
  // for(i=1;i<n;i++){
  //   if(l[i-1]=='W'&&l[i]=='W')t+=2;
  //   else if(l[i]=='W')t++;
  // }
  // cout<<max(t,j)<<"\n";
  // return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}