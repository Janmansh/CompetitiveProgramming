#include <bits/stdc++.h>

// 1. dp
typedef long double ld;
#define int long long

#define gcd            __gcd
#define endl           "\n"
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            998244353
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define f              first
#define s              second
#define lb             lower_bound
#define ub             upper_bound
#define ins            insert
#define sz(x)          (int)(x).size()
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m) {
    return power(a, m - 2, m);
}
int fact[300001];
int fact_inv[300001];
void pre()
{
    fact[0]=1;
    fact_inv[0]=1;
    for(int i=1;i<=300000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        fact_inv[i]=(fact_inv[i-1]*modi(i,mod))%mod;
    }
}
int ncr(int n,int r)
{
    if(r>n)
        return 0;
    return (fact[n]*((fact_inv[r]*fact_inv[n-r])%mod))%mod;
}
void solve() {
    int n;
    cin>>n;
    n+=n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int val=ncr(n,n/2);
    int ans=0;
    for(int i=0;i<n/2;i++)
    {
        ans-=a[i];
        ans+=mod;
        ans%=mod;
    }
    for(int i=n/2;i<n;i++)
    {
        ans+=a[i];
        ans%=mod;
    }
    cout<<(ans*val)%mod<<endl;
}

int32_t main() {
    nitin;
pre();
    solve();
}
