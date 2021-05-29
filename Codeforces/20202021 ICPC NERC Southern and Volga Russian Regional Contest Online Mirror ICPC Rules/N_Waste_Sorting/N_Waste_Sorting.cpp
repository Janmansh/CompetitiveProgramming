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
        lli c1,c2,c3;
        cin>>c1>>c2>>c3;
        lli a1,a2,a3,a4,a5;
        cin>>a1>>a2>>a3>>a4>>a5;
        c1-=a1;
        c2-=a2;
        c3-=a3;
        if(c1<0 or c2<0 or c3<0){
            cout<<"NO"<<endl;
        }
        else{
            a4-=c1;
            a5-=c2;
            if(a4<=0 and a5<=0){
                cout<<"YES"<<endl;
            }
            else if(a4<=0 and a5-c3<=0){
                cout<<"YES"<<endl;
            }
            else if(a4-c3<=0 and a5<=0){
                cout<<"YES"<<endl;
            }
            else if(a4>=0 and a5>=0 and a4+a5-c3<=0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}