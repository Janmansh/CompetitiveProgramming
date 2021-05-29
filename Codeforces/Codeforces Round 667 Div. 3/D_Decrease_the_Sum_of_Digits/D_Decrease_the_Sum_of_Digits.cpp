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
  ll n,i,j,s;
  cin>>n>>s;
  ll sum=0,temp=n,ans=0;
  vector<int>v(100);
  for(i=0;i<100;i++)v[i]=0;
  j=0;
  while(temp){
    sum+=temp%10;
    v[j++]=(temp%10);
    temp/=10;
  }i=1;j=0;
  while(sum>s){
    sum-=v[j];sum++;
    ans+=((10-v[j])*i);
    int z=j+1;
    v[z]++;
    while(v[z]>10){
      v[z]=0;
      v[z+1]++;z++;sum-=9;
    }
    i*=10;j++;
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  t=1;
  cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}