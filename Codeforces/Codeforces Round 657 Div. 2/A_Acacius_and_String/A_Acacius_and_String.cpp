#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t; 
    while (t--){
        ll n;
        cin >> n; string s;cin>>s;string d="abacaba";ll count=0;
        for (ll i=0;i<n-6;i++){
            ll flag=0;
            for (ll j=i;j<i+7;j++) {
                if(s[j]!=d[j-i]){
                    flag=1;
                    break;
                }}
            if(flag==0){
                count++;
            }}
        if(count>1) {
            cout<<"No"<<endl;
            continue;
        }
        if(count==1){
            for (ll i=0;i<n;i++){
                if (s[i]=='?')
                    s[i]='z';
            }
            cout<<"Yes"<<"\n";
            cout<<s<<"\n";
            continue;}
        ll y=0,index;
        for (ll i=0;i<n-6;i++){
            ll f=0;
            for (ll j=i;j<i+7;j++){
                if(s[j]!=d[j-i] && s[j]!='?'){
                    f=1;
                    break;
                }}
            if(f==0){
                string v=s;
                index=i;
                for (ll i=index;i<index+7;i++)
                    v[i]=d[i-index];
                for (ll i=0;i<n;i++){
                    if (v[i]=='?')
                        v[i]='z';}
                count=0;
                for (ll a=0;a<n-6;a++){
                    ll flag=0;
                    for (ll b=a;b<a+7;b++){
                        if(v[b]!=d[b-a]){
                            flag=1;
                            break;
                        }}
                    if(flag==0){
                        count++;
                    }}
                if(count==1){
                    y=1;
                    cout<<"Yes\n"<<v<<"\n";
                    break;
                }}}
        if(y==0){
            cout<<"No"<<"\n";
            continue;
        }
    }
}