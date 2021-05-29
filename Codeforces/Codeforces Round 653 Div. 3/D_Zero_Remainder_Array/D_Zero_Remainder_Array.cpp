#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long t,n,i,j,x,k,y;
  cin>>t;
  while(t--){
    cin>>n>>k;
    long long a[n],b[n];
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++){
      if(a[i]%k==0)b[i]=0;
      else if(a[i]<k)b[i]=k-a[i];
      else if(a[i]>k)b[i]=k-a[i]%k;
    }
    sort(b,b+n);
    if(b[n-1]==0){
      cout<<"0\n";continue;
    }
    long long ans=0;x=1;
    long long c[k];
    long long mx=0,c1=1;
        for (i=0;i<n;i++)
        {
            if (b[i]==0)
                continue;
    
            if (b[i]==b[i-1])
            {
                ans=max(ans,b[i]+c1*k);
                c1++;
            }
            else
            {
                c1=1;
                ans=max(ans,b[i]);
            }
        }
 
    // for(i=0;i<k;i++)c[i]=0;
    // for(i=0;i<n;i++){
    //   c[b[i]]++;
    // }
    // y=distance(c, max_element(c, c + k));
    // ans+=((*max_element(c, c+k)-1)*k)+1;
    // for(i=1;i<k;i++){
    //   if(c[i])ans++;
    // }
    // ans--;
    cout<<ans+1<<"\n";
  }
}