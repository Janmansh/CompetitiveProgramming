#include<bits/stdc++.h>
using namespace std;

class Geeks{ 
  
    public: 
        Geeks(){ 
            cout<<"s"; 
        } 
      
};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long k,i,j;
  cin>>k;
  if(k==1){
  cout<<"codeforces";return 0;}
  for(i=2;i<=40;i++){
    for(j=0;j<10;j++){
      int c=0;
      if(pow(i,j)*pow(i-1,10-j)>=k){
        for(int p=0;p<j;p++){
        for(int l=0;l<i;l++){
          if(c==0) cout<<"c";
          if(c==1) cout<<"o";
          if(c==2) cout<<"d";
          if(c==3) cout<<"e";
          if(c==4) cout<<"f";
          if(c==5) cout<<"o";
          if(c==6) cout<<"r";
          if(c==7) cout<<"c";
          if(c==8) cout<<"e";
          if(c==9) cout<<"s";
        }c++;}
        for(int p=j;p<10;p++){
        for(int l=0;l<i-1;l++){
          if(c==0) cout<<"c";
          if(c==1) cout<<"o";
          if(c==2) cout<<"d";
          if(c==3) cout<<"e";
          if(c==4) cout<<"f";
          if(c==5) cout<<"o";
          if(c==6) cout<<"r";
          if(c==7) cout<<"c";
          if(c==8) cout<<"e";
          if(c==9) cout<<"s";
        }c++;}
        cout<<"\n";
        return 0;
      }
    }
  }
}