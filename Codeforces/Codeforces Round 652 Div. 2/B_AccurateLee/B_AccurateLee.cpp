#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tests,n,i;
    cin>>tests;
    while(tests--){
      cin>>n;
      string s;
      cin>>s;
      long long f=0,l=n-1;
      long long ci=0,br[n];
      for(i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
          br[ci]=i;
          ci++;
        }}
        if(ci==0){cout<<s;
        }
        else if(ci==1){
          if(s[0]=='0'){
              cout<<s;
            }
            else{
              cout << "0";
            }
        }
        else{
          if(s[0]=='0'){
          for(i=0;i<br[0]+1;i++){
            cout<<'0';
          }
        cout<<0;
        for(i=n-1;i>=0;i--){
          if(s[i]=='0'){
            l=i;
            break;
          }}
          for (i=0;i<n-l-1;i++){
            cout<<'1';}   
          }
          else{
            if(s[n-1]=='0'){
              cout<<0;}
            else{
              cout<<0;for(i=n-1;i>=0;i--){
               if (s[i]=='0'){
                l=i;
                break;}}
                for(i=0;i<n-l-1;i++){cout<<'1';
                    }}}}
        cout<<"\n";}
}