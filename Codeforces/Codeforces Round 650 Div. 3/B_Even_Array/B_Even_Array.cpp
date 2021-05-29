#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,i,n;
  cin>>t;
  while(t--){
    cin>>n;
    long long a[n],o=0,e=0;
    for(i=0;i<n;i++){cin>>a[i];
    if(a[i]%2==i%2)continue;
    else{
      if(a[i]%2)o++;
      else e++;
    }
    }
    if(o==e)cout<<e<<"\n";
    else cout<<"-1\n";
  }
}