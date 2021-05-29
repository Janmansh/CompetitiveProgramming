#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tests;
    cin>>tests;
    while(tests--){
      long long n,i;
      cin>>n;long long a[2*n],o=0,e=0,odd[2*n]={0},even[2*n]={0};
      for(i=0;i<2*n;i++){
        cin>>a[i];
        if(a[i]%2){
          odd[o++]=i;
        }
        else{
          even[e++]=i;
        }}
        if(o%2){
          for(i=0;i<o-2;i+=2){
            cout << odd[i]+1 << " " << odd[i+1]+1 << endl;
          }
          for(i=0;i<e-2;i+=2){
            cout << even[i]+1 << " " << even[i+1]+1 << endl;
          }}
        else{
            for(i=0;i<o-2;i+=2){
              cout << odd[i]+1 << " " << odd[i+1]+1 << endl;
            }
            if(o!=0){
            for (i=0;i<e;i+=2){
              cout<<even[i]+1<<" "<<even[i+1]+1<<endl;
            }
            }
            else{
              for(i=0;i<e-2;i+=2){
                cout<<even[i]+1<<" "<<even[i+1]+1<<endl;
              }}}}
}