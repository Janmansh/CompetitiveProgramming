#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,k,i,r,j,a,b,m;
  cin>>t;
  while(t--){
    cin>>n>>k;
    if(k==0){
      cout<<"0\n";
      for(i=0;i<n;i++){
        for(j=0;j<n;j++)
          cout<<"0";
        cout<<"\n";
      }
      continue;
    }
    if(k==(n*n)){
      cout<<"0\n";
      for(i=0;i<n;i++){
        for(j=0;j<n;j++)
          cout<<"1";
        cout<<"\n";
      }
      continue;
    }
    if(k<n){
      cout<<"2\n";
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(i==j&&k){
            cout<<"1";
            k--;
          }
          else cout<<"0";
        }
        cout<<"\n";
      }
      continue;
    }
    if(k==n){
      cout<<"0\n";
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(i==j&&k){
            cout<<"1";
            k--;
          }
          else cout<<"0";
        }
        cout<<"\n";
      }
      continue;
    }
    if(k%n==0){
      cout<<"0\n";
      long long x=(k/n);
      //x--;
      long long ans[n][n];
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          ans[i][j]=0;
        }
        //cout<<"\n";
      }
      for(i=0;i<x;i++){
        for(j=0;j<n;j++){
          for(int z=0;z<n;z++){
            if(z==j+i)ans[j][z]=1;
          }
        }
        for(j=1;j<=i;j++){
          ans[n-j][i-j]=1;
        }
      }
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cout<<ans[i][j];
        }
        cout<<"\n";
      }
      continue;
    }
    cout<<"2\n";
      long long x=(k/n);
      //x--;
      long long ans[n][n];
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          ans[i][j]=0;
        }
        //cout<<"\n";
      }
      for(i=0;i<x+1;i++){
        for(j=0;j<n;j++){
          for(int z=0;z<n;z++){
            if((z==j+i)&&(k)){if(ans[j][z]!=1){ans[j][z]=1;k--;}}
          }
          
       }
        for(j=1;j<=i;j++){
          if((j>=1)&&k){
            if(ans[n-j][i-j]!=1)
            ans[n-j][i-j]=1;k--;
          }
        }
      }
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cout<<ans[i][j];
        }
        cout<<"\n";
      }
  }
}