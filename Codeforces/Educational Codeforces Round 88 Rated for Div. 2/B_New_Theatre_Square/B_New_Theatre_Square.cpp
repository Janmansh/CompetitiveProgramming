#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t;
  cin>>t;
  while(t--){
  long long n,m,x,y,i,j,ans=0,w=0,w1=0;
  cin>>n>>m>>x>>y;
  string s[n];
  for(i=0;i<n;i++)cin>>s[i];
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(s[i][j]=='.')w++;
    }
  }
  if(2*x<=y){
    cout<<w*x<<endl;
    continue;
  }
  else{
    for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(s[i][j]=='.'&&s[i][j+1]=='.'){
        w-=2;
        w1++;
        s[i][j]=',';s[i][j+1]=',';
      }
    }
  }
  cout<<w*x+w1*y<<endl;
  }
}
}