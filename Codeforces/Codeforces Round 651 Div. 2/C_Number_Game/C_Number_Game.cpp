#include<bits/stdc++.h>
using namespace std;
int main(){
  long long t,n,i;
  cin>>t;
  while(t--){
    cin>>n;
    if(n==1){
      cout<<"FastestFinger\n";
      continue;
    }
    if(n==2||n%2){
      cout<<"Ashishgup\n";
      continue;
    }
    else{
      int c=0,j=0;
      long long x=n;
      while(x){
        if(x%2==0){j++;x/=2;}
        else break;
      }
      for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
          if(i%2)c++;
          else if((n/i)%2)c++;
        }
      }
      if((j==1&&c>1)||(j>1&&c>0)){
        cout<<"Ashishgup\n";
        continue;
      }
      else{
        cout<<"FastestFinger\n";
        continue;
      }
    }
  }
}