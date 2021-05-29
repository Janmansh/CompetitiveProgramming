#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define double long double

//ll fact[200005];

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

// int gcd (int a, int b) {
//     return b ? gcd (b, a % b) : a;
// }

// ll inv(ll a, ll p){
// 	return powermod(a,mod-2);
// }
 
// ll nCr(ll n, ll r, ll p){
// 	if(r > n) return 0;
// 	ll t1 = fact[n];
// 	ll t2 = inv(fact[r],p);
// 	ll t3 = inv(fact[n-r],p);
 
// 	return (((t1*t2)%p)*t3)%p;
// }



void solve(){
  ll n,i,j,m,w,h;
  cin>>n; ll a[n]; for(i=0;i<n;i++)cin>>a[i];
  vector<int>o,e;
  for(i=0;i<n;i++){
    if(a[i]%2)o.pb(a[i]);
    else e.pb(a[i]);
  }
  sort(o.begin(),o.end());
  sort(e.begin(),e.end());
  ll al=0,bo=0;
  for(i=0;i<n;i++){
    if(i%2){
      if(o.size()>0){
        if(e.size()>0){
        if(o[o.size()-1]>=e[e.size()-1]){
          
          bo+=o[o.size()-1];
          o.pop_back();
        } 
        else e.pop_back();}
        else{
          bo+=o[o.size()-1];
          o.pop_back();
        }
      }
      else{
        e.pop_back();
      }
    }
    else{
      if(e.size()>0){
        if(o.size()>0){
        if(o[o.size()-1]<=e[e.size()-1]){
          al+=e[e.size()-1];
          e.pop_back();
        }
        else o.pop_back();}
        else{
          al+=e[e.size()-1];
          e.pop_back();
        }
      }
      else{
        o.pop_back();
      }
    }
  }
  if(al>bo){
    cout<<"Alice\n";
  }
  else if(bo>al){
    cout<<"Bob\n";
  }
  else{
    cout<<"Tie\n";
  }
  // ll ans=0;
  // ll v[n]={0};
  // for(i=0;i<n;i++){
  //   if(v[i])continue;
  //   int c=0;
  //   for(j=i;j<n;){
  //     c+=a[j];v[j]=1;j+=a[j];
  //   }
  //   ans=max(ans,c);
  // }
  // while(1){
  //   int f=1;
  //   for(i=0;i<n;i++){
  //     if(v[i]==0){f=0;break;}
  //   }
  //   if(f)break;
  //   int c=0;
  //   for(;i<n;){
  //     c+=a[i];
  //     v[i]=1;
  //     i+=a[i];
  //   }
  //   ans=max(ans,c);
  // }
  //cout<<ans<<"\n";
  // sort(a,a+n);
  // ll s=0;
  // for(i=0;i<n;i++)s+=a[i];
  // if(s%2){
  //   cout<<"No\n";return;
  // }
  // ll o=0,t=0;
  // for(i=0;i<n;i++){
  //   if(a[i]==1)o++;
  //   else t++;
  // }
  // s/=2;
  // if(o>=s){
  //   cout<<"Yes\n";return;
  // }
  // if(o==0&&t%2){
  //   cout<<"No\n";return;
  // }
  // cout<<"Yes\n";
  // cin>>w>>h>>n;
  // j=0;
  // i=w*h;
  // while(i%2==0){
  //   j++;
  //   i/=2;
  // }
  // if(power(2ll,j)>=n){
  //   cout<<"YES\n";
  // }
  // else cout<<"NO\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
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