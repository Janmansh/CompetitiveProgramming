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
  ll b,i,j,n; cin>>n;
  char s,f;
  char a[n][n];
  //cin>>s;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      // if(i==0&&j==0)continue;
      // if(i==n-1&&j==n-1)continue;
      cin>>a[i][j];
      a[i][j]-=48;
    }
  }
  //cin>>f;
  ll o=0,z=0;
  ll ab[4]={0};
  if(a[0][1]==1){o++;ab[0]=1;} else z++;
  if(a[1][0]==1){o++;ab[1]=1;} else z++;
  if(a[n-1][n-2]==1){o++;ab[2]=1;} else z++;
  if(a[n-2][n-1]==1){o++;ab[3]=1;} else z++;
  if(o==0||z==0){
    cout<<"2\n";
    cout<<"1 2\n2 1\n";
    return;
  }
  else if(z==1){
    if(ab[0]==0){
      cout<<"1\n2 1\n";
      return;
    }
    else if(ab[1]==0){
      cout<<"1\n1 2\n";
      return;
    }
    else if(ab[2]==0){
      cout<<"1\n"<<n-1<<" "<<n<<"\n";
      return;
    }
    else{
      cout<<"1\n"<<n<<" "<<n-1<<"\n";
      return;
    }
  }
  else if(o==1){
    if(ab[0]==1){
      cout<<"1\n2 1\n";
      return;
    }
    else if(ab[1]==1){
      cout<<"1\n1 2\n";
      return;
    }
    else if(ab[2]==1){
      cout<<"1\n"<<n-1<<" "<<n<<"\n";
      return;
    }
    else{
      cout<<"1\n"<<n<<" "<<n-1<<"\n";
      return;
    }
  }
  else{
    if(a[0][1]==1&&a[n-1][n-2]==0&&a[n-2][n-1]==0&&a[1][0]==1){
      cout<<"0\n";
      //cout<<"1 2\n2 1\n";
    }
    else if(a[0][1]==0&&a[n-1][n-2]==1&&a[n-2][n-1]==1&&a[1][0]==0){
      cout<<"0\n";
    }
    else if(a[0][1]==1&&a[n-1][n-2]==1&&a[n-2][n-1]==0&&a[1][0]==0){
      cout<<"2\n1 2\n"<<n-1<<" "<<n<<"\n";
    }
    else if(a[0][1]==1&&a[n-1][n-2]==0&&a[n-2][n-1]==1&&a[1][0]==0){
      cout<<"2\n1 2\n"<<n<<" "<<n-1<<"\n";
    }
    else if(a[0][1]==0&&a[n-1][n-2]==1&&a[n-2][n-1]==0&&a[1][0]==1){
      cout<<"2\n1 2\n"<<n<<" "<<n-1<<"\n";
    }
    else if(a[0][1]==0&&a[n-1][n-2]==0&&a[n-2][n-1]==1&&a[1][0]==1){
      cout<<"2\n1 2\n"<<n-1<<" "<<n<<"\n";
    }
    return;
  }
  // ll t1=a,t2=b;
  // ll ab[32]={0},bb[32]={0};
  // i=0;
  // while(a){
  //   ab[i]=a%2;
  //   a/=2;i++;
  // }
  // i=0;
  // while(b){
  //   bb[i]=b%2;
  //   b/=2;i++;
  // }
  // ll ans[32];
  // for(i=0;i<32;i++){
  //   if(ab[i]==bb[i])ans[i]=ab[i];
  //   else ans[i]=0;
  // }
  // ll an=0;
  // for(i=0;i<32;i++){
  //   an+=(power(2,i)*ans[i]);
  // }
  // cout<<(an^t1)+(an^t2)<<"\n";
  return;
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