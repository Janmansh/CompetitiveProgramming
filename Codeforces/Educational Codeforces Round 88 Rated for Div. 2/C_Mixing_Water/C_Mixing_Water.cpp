#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long te;
  cin>>te;
  while(te--){
  long long h,c,t,ans=0,t1=0,i,ans1;
  cin>>h>>c>>t;
  if(h==t){
    cout<<"1"<<"\n";continue;
  }
  if(abs(h-t)<abs(c-t)){
    float a=(t-h-1.0+1.0)/(h+c-2*t);
    if(a-floor(a)==0){ans=a;
    cout<<2*ans+1<<"\n";continue;}
    ans=floor(a);
    ans1=ceil(a);
    float f=abs((((ans+1)*h+ans*c)/(2*ans+1.0))-t);
    float f1=abs((((ans1+1)*h+ans1*c)/(2*ans1+1.0))-t);
    if(f1<f)cout<<2*ans1+1<<"\n";
    else{
      cout<<2*ans+1<<"\n";
      continue;
    }
    // else{
    //   float y=h-t;
    //   for(i=1;i<=ceil(a);i++){
    //     float x=(((i+1)*h+i*c)/(2*i+1.0)-t);
    //     if(x<0)x*=(-1);
    //     if(x<y){y=x;continue;}
    //     else break;
    //   }
    //   cout<<2*i-1<<"\n";
    // }
  }
  else{
    cout<<"2"<<"\n";
  }
}
}