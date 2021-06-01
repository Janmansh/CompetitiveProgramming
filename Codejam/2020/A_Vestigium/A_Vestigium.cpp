#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,j,x=1;
    cin>>t;
    while(t--){
        int k=0,r=0,c=0;
        cin>>n;
        int a[n][n],r1[n],c1[n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(i=0;i<n;i++){
            k+=a[i][i];
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                r1[j]=0,c1[j]=0;
            }
            for(j=0;j<n;j++){
                r1[a[i][j]-1]++;
                c1[a[j][i]-1]++;
            }
            for(j=0;j<n;j++){
                if(r1[j]>1){
                    r++;
                    break;
                }
            }
            for(j=0;j<n;j++){
                if(c1[j]>1){
                    c++;
                    break;
                }
            }
        }
        printf("Case #%d: %d %d %d\n",x,k,r,c);
        x++;
    }
}