#include<bits/stdc++.h>
using namespace std;
int main(){
    long t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        if((n/2)%2){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(i=1;i<=n-3;i+=2){
            cout<<i<<" ";
        }
        cout<<n+n/2-1<<endl;
    }
}