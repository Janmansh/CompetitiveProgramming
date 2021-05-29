#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i,r,j,a,b,m;
  cin>>t;
  while(t--){
    cin>>a>>b>>n>>m;
    if((a+b)<(n+m)){
        cout<<"NO\n";continue;
    }
    if(min(a,b)>=m){
      cout<<"YES\n";continue;
    }
    cout<<"NO\n";//continue;
  }
}