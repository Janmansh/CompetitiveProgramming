#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t,n,i,x,j;
  cin>>t;
  while(t--){
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)cin>>a[i];
    if(is_sorted(a,a+n)){
      cout<<"2\n";
      cout<<"1 "<<n<<"\n";
      continue;
    }
    int f=1;
    for(i=0;i<n-1;i++){
      if(a[i]<a[i+1]){f=0;break;}
    }
    if(f){
      cout<<"2\n";
      cout<<n<<" 1"<<"\n";
      continue;
    }
    vector<ll> b;
    b.push_back(a[0]);
    for(i=1;i<n;i++){
      if(i==n-1){b.push_back(a[i]);break;}
      if((a[i+1]-a[i])*(a[i]-a[i-1])<0)b.push_back(a[i]);
    }
    cout<<b.size()<<"\n";
    for(auto it=b.begin();it!=b.end();++it){
      cout<<*it<<" ";
    }
    cout<<"\n";
  }
}