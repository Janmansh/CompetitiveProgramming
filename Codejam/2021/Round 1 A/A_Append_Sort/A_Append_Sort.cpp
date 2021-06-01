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
    ll n,i,j;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)cin>>a[i];
    ll ans=0,z;
    for(i=0;i<n-1;i++){
        if(a[i]<a[i+1])continue;
        vector<int>f;
        vector<int>s;
        int ff=a[i],ss=a[i+1];
        while(ff){
            f.pb(ff%10);
            ff/=10;
        }
        vector<int>sss;
        j=0;
        while(ss){
            j++;
            s.pb(ss%10);
            ss/=10;
        }
        
        for(z=0;z<f.size()-j;z++)sss.pb(0ll);
        for(z=0;z<s.size();z++)sss.pb(s[z]);
        int flag=0;
        // for(z=f.size()-1;z>=f.size()-j;z--){
        //     if(sss[z]<f[z]){
        //         flag=1;
        //         ans+=f.size()-s.size()+1;
        //         a[i+1]*=(power(10, f.size()-s.size()+1));
        //         break;
        //     }
        // }
        // if(flag)continue;
        int xx=0;
        for(z=0;z<sss.size();z++)xx+=(sss[z]*power(10, z));
        if(xx>a[i]){
            a[i+1]=xx;
            ans+=(f.size()-j);
            continue;
        }
        //cout<<xx<<" ";
        flag=1;
        for(z=sss.size()-j-1;z>=0;z--){
            if(f[z]<9&&flag){
                sss[z]=f[z]+1;
                break;
            }
            else{
                sss[z]=f[z];
            }
        }
        xx=0;
        for(z=0;z<sss.size();z++)xx+=(sss[z]*power(10, z));
        if(xx>a[i]){
            a[i+1]=xx;
            ans+=(f.size()-j);
        }
        else{
            ans+=f.size()-s.size()+1;
            a[i+1]*=(power(10, f.size()-s.size()+1));
        }
        //cout<<xx<<" ";
    }
    cout<<ans<<"\n";
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
  ll x=1;
  while (t--){
      cout << "Case #"<<x<<": ";
      x++;
    solve();
  }
  return 0;
}