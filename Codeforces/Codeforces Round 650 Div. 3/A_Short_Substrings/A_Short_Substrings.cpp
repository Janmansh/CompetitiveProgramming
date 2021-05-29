#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,i;
  cin>>t;
  while(t--){
    string b;
    long long n=b.length();
    vector<char>a;
    cin>>b;
    if(b.length()==2){
      cout<<b<<"\n";
      continue;
    }
    a.push_back(b[0]);
    long long j=1;
    for(i=1;i<b.length();i+=2){
      a.push_back(b[i]);
    }
    for(auto it=a.begin();it!=a.end();++it){
      cout<<*it;
    }
    cout<<"\n";
  }
}