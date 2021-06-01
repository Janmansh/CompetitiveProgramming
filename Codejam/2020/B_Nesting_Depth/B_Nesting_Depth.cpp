#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i,x=1;
    string s;
    cin>>t;
    scanf("\n");
    while(t--){
        getline(cin,s);
        int n=s.length();
        if(s.at(0)=='1'){
            s.insert(0,"(");
            n++;
        }
        if(s.at(n-1)=='1'){
            n++;
            s.insert(n-1,")");
        }
        for(i=1;i<n;i++){
            if(s.at(i)=='1'&&s.at(i-1)!='1'&&s.at(i-1)!='('){
                s.insert(i,"(");
                i++;
                n++;
            }
            // if(s.at(n-i-1)=='1'&&s.at(n-i)!=1&&s.at(n-i)!=')'){
            //     n++;
            //     s.insert(n-i,")");
            // }
        }
        for(i=n-2;i>0;i--){
            if(s.at(i)=='1'&&s.at(i+1)!='1'&&s.at(i+1)!=')'){
                n++;
                s.insert(i+1,")");
            }
        }
        printf("Case #%d: ",x);
        x++;
        cout<<s<<endl;
    }
}