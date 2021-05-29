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
bool check(double time,int a[],int l,int n){
                   double start=0,dis=0,speed=1,end=l;
                   double f=time;
                   for(int i=0;i<n;i++){
                    dis=a[i]-dis;
                    double to=dis/speed;
                    if(to>=time){
                        start+=speed*time;
                        time=0;
                        break;
                    }
                    else{
                        start=a[i];
                        time-=to;
                        speed++;
                    }
                    dis=a[i];
                   }
                   start+=speed*time;
                   dis=l;time=f;speed=1;
                   for(int i=n-1;i>=0;i--){
                    dis=dis-a[i];
                    double to=dis/speed;
                    if(to>=time){
                        end-=speed*time;
                        time=0;
                        break;
                    }
                    else{
                        end=a[i];
                        time-=to;
                        speed++;
                    }
                    dis=a[i];
                   }
                   end-=speed*time;
                   if(start>=end){
                       return true;
                   }
                   else{
                       return false;
                   }
               }

void solve(){
  ll n,i,j,k,end;cin>>n>>end;
  ll a[n];
  //vector<ll>p;
  for(i=0;i<n;i++)cin>>a[i];
   double l=0,r=end,ans=-1;
  for(int i=0;i<100;i++){
    double mid=(l+r)/2;
    if(check(mid, a, end, n)){r=mid;ans=mid;
    }
    else l=mid;
  }
  printf("%.8f\n",ans);
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