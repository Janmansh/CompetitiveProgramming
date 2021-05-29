#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n,x,i,j;
    cin>>t;
    while(t--){
        cin>>n>>x;
        long long u[n-1],v[n-1],k=0;
        for(i=0;i<n-1;i++){
            cin>>u[i]>>v[i];
            if(u[i]==x||v[i]==x)k++;
        }
        if(k<2){
            cout<<"Ayush\n";
        }
        else{
            if((n-2)%2)cout<<"Ashish\n";
            else cout<<"Ayush\n";
        }
    }
}