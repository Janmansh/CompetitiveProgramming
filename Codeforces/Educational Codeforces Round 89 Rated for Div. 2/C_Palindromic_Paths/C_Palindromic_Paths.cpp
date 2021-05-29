#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t,n,m,i,j;
    cin >> t;
    while (t--){
        cin>>n>>m;
        long long a[n][m];
        for (i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        long long ans=0,k;
        for (k=0;k<n+m;k++){
            long long r=n+m+1;
            if ((n+m-1)%2==1){
                r=(n+m-1)/2;
            }
            long long count=0;
            long long sum=0;
            for (i=0;i<n;i++){
                for (j=0;j<m;j++){
                    long long d=min(i+j,n-i-1+m-j-1);
                    if(d==k && k!=r){
                        sum+=a[i][j];
                        count++;
                    }
                }
            }
            ans+=min(count-sum,sum);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}