#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;

ll good(int in,int l,int r)
{
    if (l==r-1)
    {
        return ((s[l] == 'a'+in) ? 0 : 1);
    }
    
    int ans=0;
    int a1=0,a2=0;
    int mid=(l+r)/2;
    int count=(r-l)/2;
    for (int i=l;i<mid;i++)
    {
        if (s[i]=='a'+in)
            a1++;
    }
    
    for (int i=mid;i<r;i++)
    {
        if (s[i]=='a'+in)
            a2++;
    }
    
    return min(count-a1+good(in+1,mid,r),count-a2+good(in+1,l,mid));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        
        cin >> s;
        
        int ans=good(0,0,n);
        
        cout << ans << endl;
    }
    
    return 0;
}