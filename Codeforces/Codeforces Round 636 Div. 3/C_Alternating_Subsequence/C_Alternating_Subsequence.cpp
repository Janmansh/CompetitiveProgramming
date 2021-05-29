#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        long long a[n],ans=0,f=0,o=0,e=0;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        //cout<<*max_element(a,a+1);
        for(i=0;i<n;i++){
            if(a[i]>0){
                f=0;
            }
            else{
                f=1;
            }
            if(f){
                ans+=(*max_element(a+i-e,a+i));
                if(e==0){
                    ans-=a[i];
                }
                e=0;
                o++;
            }
            else{
                ans+=(*max_element(a+i-o,a+i));
                if(o==0){
                    ans-=a[i];
                }
                o=0;
                e++;
            }
            if(i==(n-1)){
                if(f){
                    ans+=(*max_element(a+i-o+1,a+i+1));
                }
                else{
                    ans+=(*max_element(a+i-e+1,a+i+1));
                }
            }
        }
        cout<<ans<<endl;
    }
}