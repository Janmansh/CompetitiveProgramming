#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,j,i;
  cin>>t;
  long a[t];
  for(i=0;i<t;i++){
    cin>>a[i];
    if(a[i]%4==0)cout<<"YES\n";
    else cout<<"NO\n";
  }
}