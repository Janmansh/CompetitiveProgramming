#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mp make_pair


void solve(){
    ll n,i,j, mod = 1000000007;
    cin>>n;
    string s;
    cin>>s;
    vector<int>dp(n, 0);
    int x = 0;
    int p = 0;
    int ans = 0;
    for(i=0;i<n;i++){
        if(s[i] == 'F')continue;
        else if(s[i] == 'X' and x == -1){
            dp[i] = dp[p];
            p = i;
        }
        else if(s[i] == 'X' and x == 1){
            x = -1;
            dp[i] = p+1;
            p = i;
        }
        else if(s[i] == 'X'){
            x = -1;
            p = i;
        }
        else if(s[i] == 'O' and x == 1){
            dp[i] = dp[p];
            p = i;
        }
        else if(s[i] == 'O' and x == -1){
            x = 1;
            dp[i] = p+1;
            p = i;
        }
        else if(s[i] == 'O'){
            x = 1;
            p = i;
        }
    }
    // for(i=0;i<n;i++)cout << dp[i] << " ";
    // cout << "\n";
    x = 0;
    if(s[0] == 'X')x = -1;
    else if(s[0] == 'O')x = 1;
    for(i=1;i<n;i++){
        if(s[i] == 'F'){
            dp[i] = dp[i-1];
        }
        else if(s[i] == 'X' and x == -1){
            dp[i] = dp[i-1];
        }
        else if(s[i] == 'X'){
            x = -1;
            dp[i] += dp[i-1];
        }
        else if(s[i] == 'O' and x == 1){
            dp[i] = dp[i-1];
        }
        else if(s[i] == 'O'){
            x = 1;
            dp[i] += dp[i-1];
        }
        dp[i]%=mod;
    }
    // for(i=0;i<n;i++)cout << dp[i] << " ";
    // cout << "\n";
    for(i=0;i<n;i++){
        ans+=dp[i];
        ans%=mod;
    }
    cout << ans << "\n";
    return;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    cin>>t;
    // srand(time(0));
    // fact[0]=1;
    // for(int i=1;i<200001;i++){
    //     fact[i]=i*fact[i-1];
    //     fact[i]%=mod;
    // }
    int x = 1;
    while (t--){
        cout << "Case #" << x << ": ";
        x++;
        solve();
    }
    return 0;
}