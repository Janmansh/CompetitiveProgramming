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
vector<ll> primeFactor(ll n){
	vector<ll> q;
	for(int i=2;i<=sqrt(n);i++){
	if(n%i==0){
		int c=0;
		while(n%i==0){
			n/=i;
			c++;
		}
		q.pb(i);
	}
  }
  if(n>1){
			q.pb(n);
	}
	return q;
}
			




void solve(){
  ll p,q; cin>>p;//sc.nextLong();
	cin>>q;//=sc.nextLong();
	ll div=q;
	vector<ll> qu=primeFactor(q);
	ll ans=p;
	if(p%q==0){
		ans=0;
		ll t=p;
		while(qu.size()>0){
						ll k=qu[qu.size()-1];
            qu.pop_back();
						while(t%q==0){
							t/=k;
					  }
						//pw.println(t+" "+k);
						ans=max(ans, t);
						t=p;
					}
				}
				cout<<ans<<"\n";
        return;
  // ll a,b,c,d,i,j; cin>>a>>b>>c>>d;
  // cout<<min(a+b,a+c)<<"\n";
  // ll n,i,j,x; cin>>n>>x;
  // ll a[n],b[n];
  // for(i=0;i<n;i++)cin>>a[i]; for(i=0;i<n;i++)cin>>b[i];
  // sort(a,a+n); sort(b,b+n,greater<ll>());
  // for(i=0;i<n;i++){
  //   if(a[i]+b[i]>x){
  //     cout<<"No\n";return;
  //   }
  // }
  // cout<<"Yes\n";
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