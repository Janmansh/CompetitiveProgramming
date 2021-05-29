#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){  
  ll n,k1,k2,i,j,sum=0,x;
  cin>>n>>x;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  // if(x>a[n-1]){
  //   cout<<"0\n";return;
  // }
  for(i=1;i<n;i++)a[i]+=a[i-1];
  if(a[n-1]>=(n*x)){cout<<n<<"\n";return;}
  for(i=0;i<n-1;i++){
    if((a[n-1]-a[i])>=((n-i-1)*x)){
      break;
    }
  }
  if(i==n-1)cout<<0<<"\n";
  else cout<<n-i-1<<"\n";
  return;
}

int main(){
  ll t; cin>>t;
  while (t--)
    solve();
}