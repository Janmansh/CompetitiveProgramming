#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#include<time.h>

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
  int n,m,i,j,ans=0;
  cin>>n>>m;
  string s[n];
  for(i=0;i<n;i++)cin>>s[i];
  i=0,j=0;
  int u=0;
  while(i<=n-1&&j<=m-1){
    if(s[i][j]=='*')ans++;
    //cout << i << " " << j <<"\n";
    int dist = 10000;
    int z,l;
    int x=-1,y=-1;
    if(u==0){
      if(j==m-1){
        for(z=i+1;z<n;z++){
          if(s[z][j]=='*')ans++;
        }
        break;
      }
      if(s[i][j+1]=='*'){
        j++;
        continue;
      }
      if(i+1<n){
        if(s[i+1][j]=='*'){u=1;i++;continue;}
      }
      j++;
      continue;
      z = i+1;
      // if(j==m-1){
      //   for(z=i+1;z<n;z++){
      //     if(s[z][j]=='*')ans++;
      //   }
      //   break;
      // }
      // if(i==n-1){
      //   for(z=j+1;z<m;z++){
      //     if(s[i][z]=='*')ans++;
      //   }
      //   break;
      // }
      for(z=j+1;z<m;z++){
        if(s[i][z]=='*'&&z-j<dist){
          dist = z-j;
          x = i;
          y = z;
        }
      }
      for(z=i+1;z<n;z++){
        if(s[z][j]=='*'&&z-i<dist){
          dist = z-i;
          y = j;
          x = z;
        }
      }
      if(x==-1&&y==-1){
        j++;
      }
      else if(x==i){
        j++;
      }
      else{
        u=1;
        i++;
      }
    // for(z=i;z<n;z++){
    //   l=j;
    //   if(z==i)l++;
    //   for(;l<m;l++){
    //     if(s[z][l]=='*'&&(l-j+z-i)<dist){
    //       dist = l-j+z-i;
    //       x=z;
    //       y=l;
    //     }
    //   }
    // }
    }
    else{
      if(i==n-1){
        for(z=j+1;z<m;z++){
          if(s[i][z]=='*')ans++;
        }
        break;
      }
      if(s[i+1][j]=='*'){
        i++;
        continue;
      }
      if(j+1<m){
        if(s[i][j+1]=='*'){u=0;j++;continue;}
      }
      i++;
      continue;
      // if(i==n-1){
      //   for(z=j+1;z<m;z++){
      //     if(s[i][z]=='*')ans++;
      //   }
      //   break;
      // }
      // if(j==m-1){
      //   for(z=i+1;z<n;z++){
      //     if(s[z][j]=='*')ans++;
      //   }
      //   break;
      // }
      for(z=i+1;z<n;z++){
        if(s[z][j]=='*'&&z-i<dist){
          dist = z-i;
          y = j;
          x = z;
        }
      }
      for(z=j+1;z<m;z++){
        if(s[i][z]=='*'&&z-j<dist){
          dist = z-j;
          x = i;
          y = z;
        }
      }
      if(x==-1&&y==-1){
        i++;
      }
      else if(x==i){
        j++;
        u=0;
      }
      else{
        i++;
      }
      // for(z=j;z<m;z++){
      // l=i;
      // if(z==j)l++;
      // for(;l<n;l++){
      //   if(s[l][z]=='*'&&(l-j+z-i)<dist){
      //     dist = l-j+z-i;
      //     x=l;
      //     y=z;
      //   }
      // }
    //}
    }
    //if(x==-1||y==-1)break;
    // if(x!=i&&u==0){
    //   u=1;
    // }
    // else if(y!=j && u==1){
    //   u=0;
    // }
    //i=x,j=y;
  }
  cout<<ans<<"\n";
  // string s;
  // cin>>s;
  // for(int i=0;i<s.length();i++){
  //   s[i]-=64;
  // }
  // for(int i=2;i<s.length();i++){
  //   if(s[i]!=(s[i-1]+s[i-2]-1)%26){
  //     cout<<"NO\n";return;
  //   }
  // }
  // cout<<"YES\n";
  // int k,l;
  // cin>>k;
  // l = sqrt(k);
  // if(sqrt(k)-l<=0.5){
  //   cout<<l<<"\n";
  //   return;
  // }
  // cout<<l<<"\n";
  // string t = "Is it rated?",s;
  // s=t;
  // //getline(cin, s);
  // //cout << s;
  // time_t futur = time(NULL) + 0.5;
  // int k = 0;
  // while(s == t){// do stuff
  //   if(time(NULL) > futur)break;
  //   string s;
  //   getline(cin,s);
  //   if(s==t)k++;
  //   //cout<<"NO\n";
  //   //cout.flush();
  // }
  // for(int i=0;i<10000;i++){
  //   cout<<"NO\n";
  //   cout.flush();
  // }
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
    solve();
  }
  return 0;
}