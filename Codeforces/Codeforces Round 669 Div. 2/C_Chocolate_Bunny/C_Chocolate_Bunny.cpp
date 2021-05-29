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
  ll n,i,j;
  cin>>n;
  i=1;j=2;
  vector<int>m,ans(n+1);
  for(i=0;i<=n;i++)ans[i]=0;
  i=1;
  ll c=2*n;
  vector<int> qu;
  for(int i=0;i<n;i++){
    qu.pb(i+1);
  }
  int h[n+1];
  for(i=0;i<n+1;i++)h[i]=0;
  while(qu.size()>1){
    int a=qu[0];
    int b=qu[1];
    qu.erase(qu.begin());
    qu.erase(qu.begin());
    cout<<"? "<<a<<" "<<b<<"\n"<<flush;
    int a1; cin>>a1;
    cout<<"? "<<b<<" "<<a<<"\n"<<flush;
    int b1; cin>>b1;
    if(a1>b1){
      ans[a-1]=a1;
      h[a1]++;
      qu.pb(b);
    }
    else{
      ans[b-1]=b1;
      h[b1]++;
      qu.pb(a);
    }
  }
                
  for(int i=1;i<=n;i++){
    if(h[i]==0){
      ans[qu[0]-1]=i;
      break;
    }
  }
  // while(c--){
  //   if(i==j){c++;j++;continue;}
  //   cout<<"? "<<i<<" "<<j<<"\n"<<flush;
  //   ll x,y;
  //   cin>>x;
  //   cout<<"? "<<j<<" "<<i<<"\n"<<flush;
  //   cin>>y;
  //   if(y>x){
  //     ans[j]=y;
  //     j++;
  //     if(j>n)break;
  //   }
  //   else{
  //     ans[i]=x;
  //     i++;
  //     if(i>=n)break;
  //   }
  // }
  // for(i=1;i<=n;i++){if(ans[i]==0){ans[i]=n;break;}}
  cout<<"! ";
  for(i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<"\n";
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