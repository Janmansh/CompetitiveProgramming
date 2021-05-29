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
  ll a,b,x,y,i,j,n;
  cin>>a>>b>>x>>y>>n;
  ll xd=a-x,yd=b-y,temp=n,a1=a,b1=b;
  if(xd+yd<=n){
    cout<<x*y<<"\n";
  }
  else{
    if(xd<=n){
      a-=xd;n-=xd;b=max(y,b-n);
    }
    else{
      a-=n;
    }
    ll x1=a*b;
    n=temp;
    if(yd<=n){
      b1=y;n-=yd;a1=max(x,a1-n);
    }
    else{
      b1-=n;
    }
    ll x2=a1*b1;
    cout<<min(x1,x2)<<"\n";
  }
  // else{
  //   if(x==1){
  //     if(xd<=n){
  //       a=x;n-=xd;b=max(y,b-n);cout<<a*b<<"\n";return;
  //     }
  //   }
  //   else if(y==1){
  //     if(yd<=n){
  //       b=y;n-=yd;a=max(x,a-n);cout<<a*b<<"\n";return;
  //     }
  //   }
  //   if(a==b){
  //     if(xd>=yd){
  //       if(xd<=n){
  //         n-=xd;
  //         a-=xd;
  //         b=max(y,b-n);
  //         cout<<a*b<<"\n";
  //       }
  //       else{
  //         a-=n;cout<<a*b<<"\n";
  //       }
  //     }
  //     else{
  //       //a-=n;cout<<a*b<<"\n";return;
  //       if(yd<=n){
  //         n-=yd;
  //         b-=yd;
  //         a=max(x,a-n);
  //         cout<<a*b<<"\n";
  //       }
  //       else{
  //         b-=n;cout<<a*b<<"\n";
  //       }
  //     }
  //   }
  //   else if(a<b){
  //     if(xd<=n){
  //       n-=xd;a-=xd;b=max(y,b-n);cout<<a*b<<"\n";return;
  //     }
  //     else{
  //       a-=n;cout<<a*b<<"\n";
  //     }
  //   }
  //   else{
  //     if(yd>=n){
  //       b-=n;cout<<a*b<<"\n";return;
  //     }
  //     else{
  //       b=y;n-=yd;a=max(x,a-n);cout<<a*b<<"\n";return;
  //     }
  //   }
  // }
  // else{
  //   if(b==a){
  //     if(x==y){
  //       b-=(n/2);
  //       a-=(n-n/2);
  //       cout<<a*b<<"\n";return;
  //     }
  //     else if(y>x){
  //       n-=(b-y);
  //       b=y;
  //       a=max(x,a-n);
  //       cout<<a*b<<"\n";return;
  //     }
  //     else{
  //       n-=(a-x);
  //       a=x;
  //       b=max(y,b-n);
  //       cout<<a*b<<"\n";return;
  //     }
  //   }
  //   else if(b>a){
  //     if(y>=a){
  //       if(b-y<=n){
  //         n-=(b-y);
  //         b=y;
  //         a=max(x,a-n);
  //         cout<<a*b<<"\n";return;
  //       }
  //       else{
  //         b-=n;cout<<a*b<<"\n";return;
  //       }
  //     }
  //     else{
  //       if(b-a<=n){
  //         n-=(b-a);
  //         b=a;
  //         if(x==y){
  //       b-=(n/2);
  //       a-=(n-n/2);
  //       cout<<a*b<<"\n";return;
  //     }
  //     else if(y>x){
  //       n-=(b-y);
  //       b=y;
  //       a=max(x,a-n);
  //       cout<<a*b<<"\n";return;
  //     }
  //     else{
  //       n-=(a-x);
  //       a=x;
  //       b=max(y,b-n);
  //       cout<<a*b<<"\n";return;
  //     }
  //       }
  //       else{
  //         b-=n;cout<<a*b<<"\n";return;
  //       }
  //     }
  //   }
  //   else{
  //     if(x>=b){
  //       if(a-x<=n){
  //         n-=(a-x);
  //         a=x;
  //         b=max(y,b-n);
  //         cout<<a*b<<"\n";return;
  //       }
  //       else{
  //         a-=n;cout<<a*b<<"\n";return;
  //       }
  //     }
  //     else{
  //       if(a-b<=n){
  //         n-=(a-b);
  //         a=b;
  //         if(x==y){
  //       b-=(n/2);
  //       a-=(n-n/2);
  //       cout<<a*b<<"\n";return;
  //     }
  //     else if(y>x){
  //       n-=(b-y);
  //       b=y;
  //       a=max(x,a-n);
  //       cout<<a*b<<"\n";return;
  //     }
  //     else{
  //       n-=(a-x);
  //       a=x;
  //       b=max(y,b-n);
  //       cout<<a*b<<"\n";return;
  //     }
  //       }
  //       else{
  //         a-=n;cout<<a*b<<"\n";return;
  //       }
  //     }
  //   }
  // }
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t;
  t=1;
  cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}