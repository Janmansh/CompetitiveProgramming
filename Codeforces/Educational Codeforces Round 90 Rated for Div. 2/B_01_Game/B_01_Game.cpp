#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,a,b,c,i;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long o=0,z=0;
        for(i=0;i<s.length();i++){
          if(s[i]=='0')z++;
          else o++;
        }
        long long ans=min(o,z);
        if(ans%2){
          cout<<"DA\n";
        }
        else cout<<"NET\n";
    }
}