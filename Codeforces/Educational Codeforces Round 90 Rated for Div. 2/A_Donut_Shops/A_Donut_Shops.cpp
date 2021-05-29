#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,a,b,c,i;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if(c>a){
            cout<<"1 ";
            if(a*b>c){
                cout<<b<<"\n";
            }
            else cout<<"-1\n";
        }
        else if(a==c&&b==1){
            cout<<"-1 -1\n";
        }
        else{
            cout<<"-1 ";
            cout<<b<<"\n";
        }
    }
}