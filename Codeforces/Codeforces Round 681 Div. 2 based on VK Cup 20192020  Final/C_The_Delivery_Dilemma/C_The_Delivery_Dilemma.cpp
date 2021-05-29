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
//void solve(){
// 				int n;cin>>n;
// 				Integer a[n][2];
// 				for(int i=0;i<n;i++){
// 					cin>>a[i][0];
// 				}
// 				for(int i=0;i<n;i++){
// 					cin>>a[i][1];
// 				}
// 				Arrays.sort(a,col(0));//des sort of col(0)
// 				long sum=0;
// 				long ans=-1;
// 				for(int i=0;i<n;i++){
// 					if(a[i][0]>sum+a[i][1]){
// 						sum+=a[i][1];
// 					}
// 					else{
// 						ans=Math.max(a[i][0], sum);
// 					}
// 				}
// 				if(ans==-1)ans=sum;
// 				pw.println(ans);

// 			}

void solve(){
  ll n,i,j; cin>>n;
  ll a[n],b[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(i=0;i<n;i++)cin>>b[i];
  vector<pair<ll,ll>>v;
  if(n==1){
    cout<<min(b[0],a[0])<<"\n";
    return;
  }
  for(i=0;i<n;i++){
    v.pb(make_pair(a[i],b[i]));
  }
  sort(v.begin(),v.end());
  ll t=v[n-1].first;
  ll c=0;
  //cout<<t<<" ";
  for(i=n-1;i>=0;i--){
    if(((c+v[i].second)<t)){
      c+=v[i].second;
      if(i==0){
        t=0;
        break;
      }
      t=v[i-1].first;
    }
    else{
      break;
    }
  }
  cout<<max(c,t)<<"\n";
  // ll n,i,j,a,b; cin>>a>>b;string s; cin>>s;
  // n=s.length();
  // vector<ll>z,o;
  // ll oo=0,zz=0;
  // for(i=0;i<n;i++){
  //   if(s[i]=='1'&&zz==0){
  //     oo++;
  //   }
  //   else if(s[i]=='1'){
  //     z.pb(zz);
  //     zz=0;
  //     o.pb(0);
  //     oo++;
  //   }
  //   else if(s[i]=='0'&&oo==0){
  //     zz++;
  //   }
  //   else{
  //     z.pb(oo);
  //     oo=0;zz++;o.pb(1);
  //   }
  // }
  // if(zz!=0){
  //   z.pb(zz);o.pb(0);
  // }
  // else if(oo!=0){
  //   z.pb(oo);o.pb(1);
  // }
  // ll ans=0;
  // for(i=0;i<z.size();i++){
  //   if(o[i]==1)ans++;
  // }
  // ans*=a;
  // i=1,j=1;
  // ll ans1=0,ans2=0;
  // // for(i=0;i<z.size();i++){
  // //   cout<<z[i]<<" ";
  // // }
  // for(i=1;i<z.size();i++){
  //   if(o[i]==0&&o[i-1]==1&&o[i+1]==1){
  //     if(b*z[i]<a){
  //       o[i]=1;
  //       ans2+=b*z[i];
  //       i++;
  //     }
  //   }
  // }
  // // for(i=0;i<z.size();i++){
  // //   cout<<o[i]<<" ";
  // // }
  // int f=0;
  // for(i=0;i<n;i++){
  //   if(o[i]==1&&f==0){
  //     f=1;ans1++;
  //   }
  //   else if(o[i]==1){
  //     continue;
  //   }
  //   else{
  //     f=0;
  //   }
  // }
  // ans2+=(ans1*a);
  // cout<<min(ans,ans2)<<"\n";
  // // if(n==1){
  // //   cout<<"4\n";return;
  // // }
  // // if(n==2){
  // //   cout<<"4 6\n";return;
  // // }
  // // j=4*n;
  // // for(i=0;i<n;i++){
  // //   cout<<j<<" ";
  // //   j-=2;
  // // }
  // // cout<<"\n";
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