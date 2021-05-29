#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long ans;
        if (k%(n-1)==0){
            ans=n*(k/(n-1))-1;
        }
        else{
            ans=n*(k/(n-1))+k%(n-1);
        }
        cout<< ans<<"\n";
    }
    return 0;
}