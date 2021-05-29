#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long a,b,c,i;
        cin>>a>>b>>c;
        if(b==0){
            if (a>0)
                for (int i=0;i<a+1;i++) cout<<"0";
            else
                for(i=0;i<c+1;i++) cout<<"1";
        }
        else{
            for (i=0;i<a+1;i++) cout<<"0";
            for (i=0;i<c+1;i++) cout<<"1";
            for (i=0;i<b-1;i++) cout<<i%2;
        }
        cout<<"\n";
    }
}