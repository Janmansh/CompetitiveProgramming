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
  ll n,i,j,m,k;
  cin>>n;
  ll a[n+1];
  for(i=0;i<n;i++)cin>>a[i];
  ll ans[n+1][n+1];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      ans[i][j]=0;
    }
    ans[i][i]=a[i];
  }
  int z=1;
  for(i=0;i<n;i++){
    k=i;
    int c=a[i];
    j=i;
    if(i==0){
      while(c--){
        ans[i][j]=a[k];
        i++;
      }
      i=0;
      continue;
    }
    c--;
    j--;
    while(c){
      if(i>=n)break;
      while(ans[i][j]==0 && j>=0){
        ans[i][j]=a[k];
        j--;
        c--;
        if(c==0)break;
      }
      //int l=j+1;
      j++;
      i++;
      if(c==0)break;
      // while(ans[i][j]!=0 && j<=k){
      //   j++;
      // }
      // while(ans[i][j]==0&&j<=k){
      //   ans[i][j]=a[k];
      //   j++;
      //   c--;
      //   if(c==0)break;
      // }
      // if(c==0)break;
      // j=l;
      // i++;
    }
    i--;
    while(ans[i][j]!=0 && j<=k)j++;
    while(c){
      while(i>k && ans[i-1][j]!=0 && j<=k){
        ans[i][j]=a[k];
        c--;
        j++;
        if(c==0)break;
      }
      if(i==k)break;
      if(c==0)break;
      i--;
      if(i==k)break;
    }
    i=k;
  }
  for(i=0;i<n;i++){
    for(j=0;j<=i;j++)cout<<ans[i][j]<<" ";
    cout<<"\n";
  }
  // vector<vector<int>>a(n);
  // map<int,pair<int,int>>mm;
  // vector<pair<int,pair<int,int>>>v;
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++){
  //     cin>>k;
  //     a[i].pb(k);
  //     v.pb(mp(k,mp(i,j)));
  //     mm[k] = mp(i,j);
  //   }
  //   //sort(a[i].begin(),a[i].end());
  // }
  // sort(v.begin(),v.end());
  
  // vector<vector<int>>ans(n);
  // ll pp=-1;
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++)ans[i].pb(pp);
  // }
  
  // i=0;
  
  // ll vis[n][m];
  // for(i=0;i<n;i++)for(j=0;j<m;j++)vis[i][j]=0;
  
  // for(i=0;i<m;i++){
  //   ans[v[i].second.first][i] = v[i].first;
  //   //cout<<v[i].second.first<<v[i].second.second<<"\n";
  //   vis[v[i].second.first][v[i].second.second] = 1;
  //   //mm[v[i].second] = i;
  //   //i++;
  //   //if(i==m)break;
  // }
  
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++){
  //     if(vis[i][j]==1){
  //       //cout<<i<<" "<<j<<"\n";
  //       continue;
  //     }
  //     else{
  //       int z;
  //       for(z=0;z<m;z++){
  //         if(ans[i][z]==-1){
  //           ans[i][z]=a[i][j];
  //           break;
  //         }
  //       }
  //       vis[i][j]=1;
  //     }
  //   }
  // }
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++)cout<<ans[i][j]<<" ";
  //   cout<<"\n";
  // }
  //sort(a.begin(),a.end());
  
  
  // ll b[18];
  // for(i=0;i<18;i++){
  //   b[i]=2050*power(10ll,i);
  // }
  // ll ans=0;
  // for(i=17;i>=0;i--){
  //   ll k = n/b[i];
  //   n-=(b[i]*k);
  //   if(k>0){
  //     ans+=k;
  //     //cout<<b[i]<<" ";
  //   }
  //   if(n==0){
  //     cout<<ans<<"\n";
  //     return;
  //   }
  // }
  // cout<<"-1\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    //cout<<"case: "<<t<<"\n";
    solve();
  }
  return 0;
}