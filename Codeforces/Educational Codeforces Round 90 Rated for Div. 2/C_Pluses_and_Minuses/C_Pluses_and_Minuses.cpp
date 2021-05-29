#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long t,i;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long ans=0,n=s.length();
        long long a[n];
        for(i=0;i<n;i++)a[i]=0;
        for(i=0;i<s.length();i++){
          if(s[i]=='-')a[i]=-1;
          else a[i]=1;
        }
        for(i=1;i<n;i++){
          a[i]+=a[i-1];
        }
        map<long long, long long> g;
        for(i=0;i<n;i++){
          g.insert(pair<int, int>(a[i], i));
        }
        long long j=0;
        while(1){
          auto it=g.find((j+1)*-1);
          if(it==g.end())break;
          ans+=(it->second);
          ans++;
          j++;
        }
        ans+=n;
        cout<<ans<<"\n";
    }
}