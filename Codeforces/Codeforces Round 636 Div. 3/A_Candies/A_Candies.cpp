#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        long long x;
        for(i=2;i<n;i++){
            x=(pow(2,i)-1);
            if(n%x==0){
                cout<<(n/x)<<endl;
                break;
            }
        }
    }
}