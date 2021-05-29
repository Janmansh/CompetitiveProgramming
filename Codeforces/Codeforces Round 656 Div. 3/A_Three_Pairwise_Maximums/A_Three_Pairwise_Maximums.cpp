#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  long long t,a,b,c,n,i,j,m;
  cin>>t;
  while(t--){
    cin>>a>>b>>c;
    if(a!=b&&b!=c&&c!=a){
      cout<<"NO\n";continue;
    }
    //if(a==1||b==1||c==1){cout<<"NO\n";continue;}
    if((a<b&&a==c)||(b<a&&b==c)||(b<c&&b==a))cout<<"NO\n";
    else if(a==b&&b==c) cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
    else cout<<"YES\n"<<max(a,max(b,c))<<" "<<min(min(a,b),c)<<" "<<min(min(a,b),c)<<"\n";
  }
}