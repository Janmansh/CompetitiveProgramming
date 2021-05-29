#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
ll MOD=1e9+7;

ll power(ll x,ll y)
{
    if (y==0)
        return 1;
    
    if (y==1)
        return x;
    
    if (y%2)
        return x*power(x,y/2)*power(x,y/2);
    else
        return power(x,y/2)*power(x,y/2);
}

void solve()
{
    ll n;
    cin >> n;
    
    ll a[2*n],b[2*n],c[2*n];
    for (ll i=0;i<2*n;i++)
    {
        cin >> a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    
    ll a1=0,h=0,a2=0,f=0;
    
    while(!is_sorted(b,b+2*n))
    {
        if (h==0)
        {
            for (ll i=0;i<2*n;i+=2)
                swap(b[i],b[i+1]);
        }
        else
        {
            for (ll i=0;i<n;i++)
                swap(b[i],b[i+n]);
        }
        h=!h;
        a1++;
        
        if (a1==2*n+1)
        {
            f++;
            break;
        }
    }
    
    h=1;
    while(!is_sorted(c,c+2*n))
    {
        if (h==0)
        {
            for (ll i=0;i<2*n;i+=2)
                swap(c[i],c[i+1]);
        }
        else
        {
            for (ll i=0;i<n;i++)
                swap(c[i],c[i+n]);
        }
        h=!h;
        a2++;
        
        if (a2==2*n+1)
        {
            f++;
            break;
        }
    }
    
    if (f==2)
    {
        cout << "-1\n";
        return;
    }
    
    cout << min(a1,a2) << "\n";
    
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t=1;
    //cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    return 0;
}