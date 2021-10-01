#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mp make_pair

int solve1(string s, int n){
    ll i,j;
    int x = 0;
    int ans = 0;
    for(i=0;i<n;i++){
        if(s[i] == 'F')continue;
        else if(s[i] == 'X' and x == -1){
            continue;
        }
        else if(s[i] == 'X' and x == 1){
            x = -1;
            ans++;
        }
        else if(s[i] == 'X'){
            x = -1;
        }
        else if(s[i] == 'O' and x == 1){
            continue;
        }
        else if(s[i] == 'O' and x == -1){
            x = 1;
            ans++;
        }
        else{
            x = 1;
        }
    }
    return ans;
}


void solve(){
    ll n,i,j, mod = 1000000007;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    if(n == 1){
        cout << "0\n";return;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            ans += solve1(s.substr(i, j-i+1), j-i+1);
            cout << i << " " << j << ": " << solve1(s.substr(i, j-i+1), j-i+1) << "\n";
            //ans%=mod;
        }
    }
    cout << ans << "\n";
    return;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    // cin>>t;
    // srand(time(0));
    // fact[0]=1;
    // for(int i=1;i<200001;i++){
    //     fact[i]=i*fact[i-1];
    //     fact[i]%=mod;
    // }
    int x = 1;
    while (t--){
        //cout << "Case #" << x << ": ";
        x++;
        solve();
    }
    return 0;
}