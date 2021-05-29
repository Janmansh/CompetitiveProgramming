#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i,j,x,k,y;
  cin>>t;
  while(t--){
    cin>>n;
    string s;
    cin>>s;
    long long ans1=0,ans2=0,o=0,e=0;
    for(i=0;i<n;i++){
      if(s[i]=='(')o++;
      else o--;
      if(o<0){ans1++;o=0;}
    }
    for(i=n-1;i>=0;i--){
      if(s[i]==')')e++;
      else e--;
      if(e<0){ans2++;e=0;}
    }
    cout<<min(ans1,ans2)<<"\n";
  }
}