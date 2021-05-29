#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,m,i,j;
  cin>>t;
  while(t--){
    cin>>n>>m;
    int a[n][m],r[n],c[m];
    for(i=0;i<n;i++)r[i]=-1;
    for(i=0;i<m;i++)c[i]=-1;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cin>>a[i][j];
        if(a[i][j]){r[i]=0;c[j]=0;}
      }
    }
    long long row=0,col=0;
    for(i=0;i<n;i++){
      if(r[i]==-1)row++;
    }
    for(i=0;i<m;i++){
      if(c[i]==-1)col++;
    }
    long long x=min(row,col);
    if(x%2)cout<<"Ashish\n";
    else cout<<"Vivek\n";
  }
}