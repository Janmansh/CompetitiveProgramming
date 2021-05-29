#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

// power function to take modulo
ll power(ll x,ll y){
  if(y==0) return 1;
  ll temp = power( x,y/2 )%mod;
  if( y%2 ){
    return (((temp*temp)%mod)*x%mod);
  }
  return (temp*temp)%mod;
}

signed main(){
int tests;cin>>tests;
  while(tests--){
    int my;cin>>my;
    int fol;cin>>fol;
    int ca;cin>>ca;
        int cb;cin>>cb;
        int a;cin>>a;
        int b;cin>>b;
        int cmax=0,i;
        for(i=0;i<=ca;i++){
          int pos=0;
          if(my-i*a<0)break;
          int m1=my-i*a,acount=0,bcount=0;
          pos+=i;
          bcount=min(m1/b,cb);
          pos+=bcount;
          int an=ca-i,bn=cb-bcount;
          if(a<b){
            acount=min(fol/a,an);
            int f1=fol-acount*a;
            pos+=acount;
            bcount=min(f1/b,bn);
            pos+=bcount;
          }
          else{
            bcount=min(fol/b,bn);
            int f1=fol-bcount*b;
            pos+=bcount;
            acount=min(f1/a,an);
            pos+=acount;
          }
          cmax=max(cmax,pos);
      }
      cout<<cmax<<"\n";}}  
        