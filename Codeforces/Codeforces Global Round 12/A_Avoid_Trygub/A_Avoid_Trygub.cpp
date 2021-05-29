#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

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
    
    string s;
    cin >> s;
    
    ll a[26]={0};
    for (ll i=0;i<n;i++)
    {
        a[s[i]-'a']++;
    }
    
    for (ll i=25;i>=0;i--)
    {
        for (ll j=0;j<a[i];j++)
        {
            char c='a'+i;
            cout << c;
        }
    }
    cout << "\n";
    
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t=1;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    return 0;
}