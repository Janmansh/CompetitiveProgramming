#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005];

ll powermod(ll x,ll y){
    if(y==0) return 1;
    ll temp = powermod( x,y/2 )%mod;
    if( y%2 ){
        return (((temp*temp)%mod)*x%mod);
    }
    return (temp*temp)%mod;
}

ll power(ll x,ll y){
    if(y==0) return 1;
    ll temp = power( x,y/2 );
    if( y%2 ){
        return (((temp*temp))*x);
    }
    return (temp*temp);
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

ll inv(ll a, ll p){
    return powermod(a,mod-2);
}
 
ll nCr(ll n, ll r, ll p){
    if(r > n) return 0;
    ll t1 = fact[n];
    ll t2 = inv(fact[r],p);
    ll t3 = inv(fact[n-r],p);
    return (((t1*t2)%p)*t3)%p;
}


void solve(){
    ll n,i,j;
    string s[2];
    cin>>n;
    cin>>s[0]>>s[1];
    vector<int>vis(n,0);
    int ans = 0, ans1 = 0;
    for(i=0;i<n;i++){
        if(s[0][i] == '0' and s[1][i] == '1'){
            vis[i] = 1;
            ans+=2;
        }
        if(s[0][i] == '1' and s[1][i] == '0'){
            vis[i] = 1;
            ans+=2;
        }
    }
    ans1 = ans;
    for(i=0;i<n;i++){
        if(vis[i] == 1)continue;
        if(s[0][i] == '0'){
            if(i == n-1){
                ans++;
            }
            else{
                if(vis[i+1] == 0 and s[0][i+1] == '1'){
                    ans+=2;
                    i++;
                }
                else{
                    ans++;
                }
            }
        }
        if(s[0][i] == '1'){
            if(i == n-1){
                continue;
            }
            else{
                if(vis[i+1] == 0 and s[0][i+1] == '0'){
                    ans+=2;
                    i++;
                }
            }
        }
    }
    for(i=n-1;i>=0;i--){
        if(vis[i] == 1)continue;
        if(s[0][i] == '0'){
            if(i == 0){
                ans1++;
            }
            else{
                if(vis[i-1] == 0 and s[0][i-1] == '1'){
                    ans1+=2;
                    i--;
                }
                else{
                    ans1++;
                }
            }
        }
        if(s[0][i] == '1'){
            if(i == 0){
                continue;
            }
            else{
                if(vis[i-1] == 0 and s[0][i-1] == '0'){
                    ans1+=2;
                    i--;
                }
            }
        }
    }
    cout << max(ans, ans1) << "\n";
    // n = s.length();
    // for(i=0;i<n;i++){
    //     if(s[i] == '0'){
    //         break;
    //     }
    // }
    // i++;
    // for(;i<n;i++){
    //     if(s[i] == '1'){
    //         break;
    //     }
    // }
    // i++;
    // for(;i<n;i++){
    //     if(s[i] == '0'){
    //         cout << "2\n";return;
    //     }
    // }
    // for(i=0;i<n;i++){
    //     if(s[i] == '0'){
    //         cout << "1\n";return;
    //     }
    // }
    // cout << "0\n";
    return;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    //cin>>t;
    // srand(time(0));
    // fact[0]=1;
    // for(int i=1;i<200001;i++){
    //     fact[i]=i*fact[i-1];
    //     fact[i]%=mod;
    // }
    while (t--){
        solve();
    }
    return 0;
}