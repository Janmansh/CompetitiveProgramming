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
  ll n,i,j,k,d; cin>>n;
  vector<ll>v(n+1);
  v[1]=0;
  vector<ll>ans(n+1,-1);
  for(i=2;i<=n;i++){
      cout<<"XOR 1 "<<i<<"\n";cout.flush();
      cin>>k;
      if(k==-1)return;
      v[i]=k;
      //cout.flush();
  }
  for(i=2;i<=n;i++){
      if(v[i]==0){
          cout<<"AND 1 "<<i<<"\n";cout.flush();
          cin>>k;
          if(k==-1)return;
          ans[1]=k;
          ans[i]=k;
          //cout.flush();
          break;
      }
  }
  if(ans[1]!=-1){
      cout<<"! "<<ans[1]<<" ";cout.flush();
      for(i=2;i<=n;i++){
          cout<<(ans[1]^v[i])<<" ";
      }
      cout<<"\n";
      cout.flush();
      return;
  }
  map<int,int>m;
  for(i=2;i<=n;i++){
      if(m.find(v[i])==m.end()){
          m[v[i]]=i;
      }
      else{
          cout<<"AND "<<m[v[i]]<<" "<<i<<"\n";cout.flush();
          cin>>k;
          if(k==-1)return;
          ans[i]=k;ans[m[v[i]]]=k;
          ans[1]=v[i]^ans[i];
          break;
      }
  }
  if(ans[1]!=-1){
      cout<<"! "<<ans[1]<<" ";
      for(i=2;i<=n;i++){
          cout<<(ans[1]^v[i])<<" ";
      }
      cout<<"\n";
      cout.flush();
      return;
  }
  ll ab,ac,bc=n-1,b=-1,c=-1;
  for(i=2;i<=3;i++){
      for(j=i+1;j<=n;j++){
          if((v[i]^v[j])==n-1){
              b=i;
              c=j;
              break;
          }
      }
      if(b!=-1)break;
  }
  cout<<"AND 1 "<<b<<"\n";cout.flush();cin>>k;ab=v[b]+2*k;if(k==-1)return;
  cout<<"AND 1 "<<c<<"\n";cout.flush();cin>>k;ac=v[c]+2*k;if(k==-1)return;
  ans[1]=(ab+ac-bc)/2;
  cout<<"! "<<ans[1]<<" ";
  for(i=2;i<=n;i++){
      cout<<(ans[1]^v[i])<<" ";
  }
  cout<<"\n";
  cout.flush();
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  while (t--){
    solve();
  }
  return 0;
}