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

void solve(){
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli inf=0,ninf=0,zero=0,nzero=0;
        umap<ld,pair<lli,lli>>hm;
        range(i,0,n){
            lli a,b,c,d;
            cin>>a>>b>>c>>d;
            ld num=d-b;
            ld den=c-a;
            if(num==0){
                if(a<c){
                    zero++;
                }
                else{
                    nzero++;
                }
            }
            else if(den==0){
                if(d>b){
                    inf++;
                }
                else{
                    ninf++;
                }
            }
            else{
                ld m=num/den;
                if(hm.find(m)==hm.end()){
                    hm.insert(pair<ld,pair<lli,lli>>(m,{0,0}));
                }
                if(a<c){
                    hm[m].first++;
                }
                else{
                    hm[m].second++;
                }
            }
        }
        lli ans=inf*ninf+zero*nzero;
        itover(hm){
            ans+=it->second.first*it->second.second;
        }
        cout<<ans<<endl;
    }
}