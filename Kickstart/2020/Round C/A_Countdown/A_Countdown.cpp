#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int l=1;
    while (t--)
    {
        int n,k,i;
        cin >> n >>  k;
        
        int a[n];
        for (i=0;i<n;i++)
            cin >> a[i];
        
        int ans=0,f=0;
        for (i=0;i<n;i++)
        {
            if (f==1 && a[i]!=a[i-1]-1)
            {
                f=0;
            }
            
            if (f==1 && a[i]==1)
            {
                ans++;
                f=0;
            }
            
            if (f==0 && a[i]==k)
            {
                f=1;
            }
        }
        cout << "Case #" << l << ": ";
        cout << ans << endl;
        l++;
    }
    
    return 0;
}