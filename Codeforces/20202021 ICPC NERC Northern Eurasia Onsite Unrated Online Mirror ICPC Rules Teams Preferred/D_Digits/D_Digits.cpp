/* 
        ~~~~~~ @spectre900 ~~~~~~~
*/
 
#include<bits/stdc++.h>
 
#define mod 1000000007
 
#define endl "\n"
#define space " "
#define li long int
#define llli __int128
#define ld long double
#define lli long long int
#define uli unsigned long int
#define cd complex<long double>
#define pi acos((long double)(-1))
#define ulli unsigned long long int

#define ms multiset
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define ums unordered_multiset

#define SEED srand(18112001)
#define modinv(x) power((x),mod-2)
#define all(x) (x).begin(),(x).end()
#define getBlock(x) (((int)(sqrt(x)/100)+1)*100)
#define range(i,beg,end) for(int i=beg;i<end;i++)
#define rrange(i,end,beg) for(int i=end;i>=beg;i--)
#define itover(x) for(auto it=(x).begin();it!=(x).end();it++)
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
 
using namespace std;
 
void solve();
 
lli power(lli n,lli k){
    if(k==0)return 1;
    if(k%2)return (n*power(n,k-1))%mod;
    return power((n*n)%mod,k/2);
}
 
lli gcd(lli a,lli b){
    return b?gcd(b,a%b):a;
}
 
lli lcm(lli a,lli b){
    return (((a*b)%mod)*modinv(gcd(a,b)))%mod;
}
 
int main(){
    SEED;
    FASTIO;
    solve();
    return 0;
}
 
#define N 100000

struct node{
    ld num=-1;
    lli p=0;
    lli ind=0;
    node *prev=NULL;
    bool take=false;
};

node max(node x, node y){
    if(x.p>y.p){
        return x;
    }
    else if(y.p>x.p){
        return y;
    }
    else if(x.num>y.num){
        return x;
    }
    else{
        return y;
    }
}

void handle(node &x){
    while(x.num>1){
        x.num/=10;
        x.p++;
    }
}

void solve(){
    lli n, d;
    cin>>n>>d;
    vector<lli>nums(n);
    vector<vector<node>>dp(n,vector<node>(10));
    range(i,0,n){
        range(j,0,10){
            dp[i][j].ind=i;
        }
    }
    range(i,0,n){
        cin>>nums[i];
    }
    dp[0][nums[0]%10].num = nums[0];
    dp[0][nums[0]%10].take = true;
    handle(dp[0][nums[0]%10]);
    range(i,1,n){
        range(j,0,10){
            dp[i][j].num = dp[i-1][j].num;
            dp[i][j].p = dp[i-1][j].p;
            dp[i][j].prev = &dp[i-1][j];
            dp[i][j].ind = i;
            dp[i][j].take = false;
        }
        lli digit = nums[i]%10;
        if(dp[i][digit].num == -1){
            dp[i][digit].num = nums[i];
            dp[i][digit].p = 0;
            dp[i][digit].ind = i;
            dp[i][digit].prev = NULL;
            dp[i][digit].take = true;
            handle(dp[i][digit]);
        }
        else{
            node ans = node();
            ans.num = nums[i];
            ans.p = 0;
            ans.prev = NULL;
            ans.take = true;
            ans.ind = i;
            handle(ans);
            dp[i][digit] = max(dp[i][digit], ans);
        }
        range(j,0,10){
            if(dp[i-1][j].num!=-1){
                lli digit = (j*(nums[i]%10))%10;
                node ans = node();
                ans.num = dp[i-1][j].num;
                ans.p = dp[i-1][j].p;
                ans.prev = &dp[i-1][j];
                ans.take = true;
                ans.ind = i;
                ans.num *= nums[i];
                handle(ans);
                if(dp[i][digit].num==-1){
                    dp[i][digit] = ans;
                }
                else{
                    dp[i][digit] = max(dp[i][digit], ans);
                }
            }
        }
    }
    if(dp[n-1][d].num==-1){
        cout<<-1;
    }
    else{
        vector<lli>ans;
        node *prev = dp[n-1][d].prev;
        if(dp[n-1][d].take){
            ans.push_back(nums[n-1]);
        }
        while(prev!=NULL){
            if(prev->take){
                ans.push_back(nums[prev->ind]);
            }
            prev = prev->prev;
        }
        cout<<ans.size()<<endl;
        itover(ans){
            cout<<*it<<space;
        }
    }
}