#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];
vector<vector<int>>tree(2005);
vector<int>visited(2005, 0);

void dfs(int r){
  if(visited[r])return;
  visited[r] = 1;
  for(int i = 0;i<tree[r].size();i++){
    if(visited[tree[r][i]])continue;
    cout<<r<<" "<<tree[r][i]<<"\n";
    cout.flush();
    dfs(tree[r][i]);
  }
}

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
  ll n,i,j;
  cin>>n;
  ll d[n+1];
  int vis[n+1] = {0};
  int mat[n+1][n+1];
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)mat[i][j]=0;
  }
  cout<<"? 1\n";
  cout.flush();
  int odd = 0,even =0;
  for(i=1;i<=n;i++){
    cin>>d[i];
    if(d[i]==1)odd=i;
    if(d[i]%2==0)even++;
  }
  if(even<=n-even){
    queue<int>q;
    q.push(1ll);
    while(!q.empty()){
      i = q.front();
      q.pop();
      if(vis[i] == 1)continue;
      vis[i] = 1;
      if(i!=1){
        cout<<"? "<<i<<"\n";
        cout.flush();
        int c = 0, t=0, x = 0;
        for(j=1;j<=n;j++)cin>>d[j];
      }
      //for(j=1;j<=n;j++)cout<<d[j]<<" ";
      for(j=1;j<=n;j++){
        if(d[j]==1 and mat[i][j]==0){
          tree[i].pb(j);
          tree[j].pb(i);
          mat[i][j]=1;
          mat[j][i]=1;
        }
        if(d[j]==2 and vis[j]==0){
          q.push(j);
        }
      }
      //cout<<t<<" "<<c<<" ";
      // if(t<=x-t){
      //   for(j=1;j<=n;j++){
      //     if(d[j]==2 and vis[j]==0){
      //       q.push(j);
      //       vis[j]=1;
      //     }
      //     if(d[j]==1)vis[j]=1;
      //   }
      // }
      // else if(c!=0){
      //   for(j=1;j<=n;j++){
      //     if(d[j] == 1 and vis[j]==0){
      //       q.push(j);
      //       vis[j]=1;
      //     }
      //     if(d[j]==2)vis[j]=1;
      //   }
      // }
    }
  }
  else{
    queue<int>q;
    q.push(odd);
    while(!q.empty()){
      i = q.front();
      q.pop();
      if(vis[i] == 1)continue;
      vis[i] = 1;
      cout<<"? "<<i<<"\n";
      cout.flush();
      int c = 0, t=0, x = 0;
      for(j=1;j<=n;j++)cin>>d[j];
      //for(j=1;j<=n;j++)cout<<d[j]<<" ";
      for(j=1;j<=n;j++){
        if(d[j]==1 and mat[i][j]==0){
          tree[i].pb(j);
          tree[j].pb(i);
          mat[i][j]=1;
          mat[j][i]=1;
        }
        if(d[j]==2 and vis[j]==0){
          q.push(j);
        }
      }
    }
  }
  cout<<"!\n";
  dfs(1ll);
  cout.flush();
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