#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  long long n,i,j,l,r,m,a=0,b=0,c=0;
  cin>>l>>r>>m;
  if(m==l){
    cout<<l<<" "<<l<<" "<<l<<"\n";return ;
  }
  if(m<l){
    if(l-m<=r-l){
        a=l;
        c=l+(l-m);
        b=l;
        cout << a << " " << b << " " << c << endl;
        return ;}}
  if(m>=l&&m<=r){
    cout<<m<<" "<<l<<" "<<l<<"\n";return ;
  }
  for(i=l;i<=r;i++){
    if(m%i<=(r-l)){
      a=i;b=l+m%i;c=l;
      break;
    }
    else if(i*(m/i+1)-m<=r-l){
      a=i;
      b=l;
      c=l+(i-m%i);
      break;
    }
  }
  cout<<a<<" "<<b<<" "<<c<<"\n";

  return ;
}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}