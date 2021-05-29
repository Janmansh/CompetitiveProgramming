#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,i,n,k,j;
  cin>>t;
  while(t--){
    cin>>n>>k;
    string s;
    cin>>s;
    int f=0;
    j=1;
    int c[26]={0};
    for(i=0;i<s.length();i++){
      c[s[i]-97]++;
    }
    if(k%n==0){
      cout<<n<<"\n";
      continue;
    }
    sort(c,c+26);
    if(k==1){cout<<c[25]<<"\n";continue;}
    for(i=n;i>0;i--){
      if(k%i==0){j=i;break;}
    }
    for(i=n;i>=j;i--){
      int count=0;
      int l=__gcd(i,k);
      for(int z=0;z<26;z++)count+=(c[z]*l)/i;
      if(count>=l){
        cout<<i<<"\n";
        break;
      }
    }
  }
}