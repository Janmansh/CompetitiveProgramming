#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
  ll n,k,i,j,ans=0,c=1,c1=0;
  cin>>n>>k;
  string s,a[k];
  cin>>s;
  sort(s.begin(),s.end());
  for(i=1;i<n;i++){
      if(s[i]!=s[i-1])c++;
  }
  if(s[k-1]!=s[0]){
    cout<<s[k-1]<<"\n";
    return;
  }
  for(i=0;i<n;i++){
    if(s[i]==s[n-1])ans++;
  }
  for(i=0;i<n;i++)if(s[i]==s[0])c1++;
  if(s[n-1]==s[0]){
    for(i=0;i<n;i++){
      a[i%k].pb(s[i]);
    }
    sort(a,a+k);
    cout<<a[k-1]<<"\n";return;
  }
  // if(c==2&&ans==(n/2)){
  //     for(i=0;i<n;i++){
  //         a[i%k].pb(s[i]);
  //     }
  //     cout<<a[0]<<"\n";return;
  // }
  if(c1==k&&c==2){
    for(i=0;i<n;i++){
          a[i%k].pb(s[i]);
      }
      cout<<a[0]<<"\n";return;
  }
  //if(ans!=k){
    for(i=0;i<k;i++){
      a[i].pb(s[i]);
    }
    for(i=k;i<n;i++)a[0].pb(s[i]);
    cout<<a[0]<<"\n";return;
  //}
  // for(i=0;i<k;i++){
  //   a[i].pb(s[i]);
  // }j=1;
  // if(k<n)a[0].pb(s[k]);
  // for(i=k+1;i<n;i++){
  //   if(s[i]==s[i-1]){
  //     a[j%k].pb(s[i]);j++;
  //   }
  //   else{
  //     a[0].pb(s[i]);j=0;
  //   }
  // }
  // sort(a,a+k);
  // cout<<a[k-1]<<"\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t;
  cin>>t;
  //t=1;
  while(t--){
    solve();
  }
}