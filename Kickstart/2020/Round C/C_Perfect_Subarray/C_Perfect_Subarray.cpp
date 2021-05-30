#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n,i,j,l=1;
    cin>>t;
    while(t--){
        cin>>n;
        long long a[n],sum,ans=0;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++){
            sum=0;
            for(j=i;j<n;j++){
                sum+=a[j];
                if(sqrt(sum)-floor(sqrt(sum))==0){
                    ans++;
                }
            }
        }
        cout << "Case #" << l << ": ";
        cout << ans << endl;
        l++;
    }
}