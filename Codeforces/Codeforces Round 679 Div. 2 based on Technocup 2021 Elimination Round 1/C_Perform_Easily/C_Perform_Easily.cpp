#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
}


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
  ll a[6],i,j,n;
  for(i=0;i<6;i++)cin>>a[i];
  cin>>n;
  ll b[n];
  for(i=0;i<n;i++)cin>>b[i];
  vector< vector<ll> > m(6*n);
  for(i=0;i<n;i++){
    vector<ll>k;
    for(j=0;j<6;j++){
      m[i*6+j].pb(b[i]-a[j]);
      m[i*6+j].pb(i);
    }
  }
  sort(m.begin(), m.end(),sortcol); 
  map<ll,ll>k;
  ll l=0,r=0,ans=1000000000000000;
  for(i=0;i<6*n;i++){
    k[m[i][1]]=m[i][0];
    while(k[m[l][1]]!=m[l][0]){
      l++;
    }
    if(k.size()>=n){
      ans=min(ans,m[i][0]-m[l][0]);
    }
  }
  cout<<ans<<"\n";
  // ll n,m,i,j;
  // cin>>n>>m; ll a[n][m],b[m][n];
  // unordered_map<ll,ll>mm;
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++){
  //     cin>>a[i][j];
  //     mm[a[i][j]]=i*m+j;
  //   }
  // }
  // int in[n];
  // for(i=0;i<m;i++){
  //   for(j=0;j<n;j++){
  //     cin>>b[i][j];
  //     if(i>0)continue;
	// 		int get=mm[b[i][j]];
	// 		in[j]=get/m;
  //   }
  // }
  // for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<a[in[i]][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
  // return;
  // vector<ll>r[n],c[m];
  // //for(i=0;i<n*m;i++){r[i]=0,c[i]=0;}
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++){
  //     c[j].pb(a[i][j]);
  //   }
  // }
  // for(i=0;i<m;i++){
  //   for(j=0;j<n;j++){
  //     r[j].pb(b[i][j]);
  //   }
  // }
  // for(i=0;i<n;i++)sort(r[i].begin(),r[i].end());
  // for(i=0;i<m;i++)sort(c[i].begin(),c[i].end());
  // ll ans[n][m];
  // // for(i=0;i<n;i++){
  // //   for(j=0;j<m;j++){
  // //     for(int k=0;k<m;k++){
  // //       if(binary_search(c[j].begin(),c[j].end(),r[i][k])){
  // //         ans[i][j]=r[i][k];
  // //         break;
  // //       }
  // //     }
  // //   }
  // // }
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++){
  //     vector<int> v(r[i].size() + c[j].size()); 
  //     vector<int>::iterator it, st;
  //   it = set_intersection(r[i].begin(), 
  //                         r[i].end(), 
  //                         c[j].begin(), 
  //                         c[j].end(), 
  //                         v.begin()); 
  //   for (st = v.begin(); st != it; ++st) 
  //       ans[i][j]=*st;
  //   }
  // }
  // for(i=0;i<n;i++){
  //   for(j=0;j<m;j++){
  //     cout<<ans[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  // return;

  // ll n,i,j;cin>>n; ll a[n];
  // for(i=0;i<n;i++)cin>>a[i];
  // vector<ll>v(n);
  // j=n-1;
  // for(i=0;i<n;i++){
  //   if(i<n/2)v[j]=-1*a[i];
  //   else v[j]=a[i];
  //   j--;
  // }
  
  // for(i=0;i<n;i++)cout<<v[i]<<" ";
  // cout<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;  
  while (t--){
    solve();
  }
  return 0;
}