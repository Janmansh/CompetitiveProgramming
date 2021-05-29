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

#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define modinv(x) power((x),mod-2)
#define all(x) (x).begin(),(x).end()
#define getBlock(x) (((int)(sqrt(x)/100)+1)*100)
#define range(i,beg,end) for(long long int i=beg;i<end;i++)
#define itover(x) for(auto it=(x).begin();it!=(x).end();it++)
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

using namespace std;

void solve();

lli power(lli n,lli k,lli m=mod){
    if(k==0)return 1;
    if(k%2)return (n*power(n,k-1,m))%m;
    return power((n*n)%m,k/2,m);
}

lli gcd(lli a,lli b){
    return b?gcd(b,a%b):a;
}

lli lcm(lli a,lli b){
    return (((a*b)%mod)*modinv(gcd(a,b)))%mod;
}

int main(){
    FASTIO;
    solve();
    return 0;
}

#define N 100000

class customConditionT{
    public:
        bool operator()(pair<lli,lli>&p1,pair<lli,lli>&p2){
            return p2.first<p1.first;
        }
};

class customConditionM{
    public:
        bool operator()(pair<lli,lli>&p1,pair<lli,lli>&p2){
            if(p1.second!=p2.second){
                return p2.second>p1.second;
            }
            return p2.first<p1.first;
        }
};

void solve(){
    lli q;
    cin>>q;
    lli counter=1;
    uset<lli>present;
    priq<pair<lli,lli>,vector<pair<lli,lli>>,customConditionT>pqt;
    priq<pair<lli,lli>,vector<pair<lli,lli>>,customConditionM>pqm;
    while(q--){
        lli t;
        cin>>t;
        if(t==1){
            lli m;
            cin>>m;
            pqt.push({counter,m});
            pqm.push({counter,m});
            present.insert(counter);
            counter++;
        }
        else if(t==2){
            while(present.find(pqt.top().first)==present.end()){
                pqt.pop();
            }
            cout<<pqt.top().first<<space;
            present.erase(pqt.top().first);
        }
        else{
            while(present.find(pqm.top().first)==present.end()){
                pqm.pop();
            }
            cout<<pqm.top().first<<space;
            present.erase(pqm.top().first);
        }
    }
}