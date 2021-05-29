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

class priorityQueueCondition{
    public:
    bool operator()(vector<lli>const&vec1,vector<lli>const&vec2){
        return vec1[2]>vec2[2];
    }
};

struct node{
    node *parent=NULL;
};

node *find(node *x){
    if(x->parent==x){
        return x;
    }
    else{
        x->parent=find(x->parent);
        return x->parent;
    }
}

void solve(){
    lli t;
    cin>>t;
    while(t--){
        lli n,m,k;
        cin>>n>>m>>k;
        vector<node>graph(n+1);
        for(int i=0;i<=n;i++){
            graph[i].parent=&graph[i];
        }
        priq<vector<lli>,vector<vector<lli>>,priorityQueueCondition>pq;
        for(int i=0;i<m;i++){
            lli a,b,w;
            cin>>a>>b>>w;
            pq.push({a,b,w});
        }
        lli counter=0;
        lli cost=0;
        lli maxw=0;
        while(counter!=n-1){
            lli a=pq.top()[0],b=pq.top()[1],w=pq.top()[2];
            pq.pop();
            node*A=find(&graph[a]);
            node*B=find(&graph[b]);
            if(A!=B){
                graph[a].parent=B;
                graph[b].parent=B;
                A->parent=B;
                counter++;
                if(w>k){
                    cost+=w-k;
                }
                maxw=max(maxw,w);
            }
        }
        if(maxw>=k){
            cout<<cost<<endl;
        }
        else{
            cost=abs(maxw-k);
            while(!pq.empty()){
                cost=min(cost,abs(pq.top()[2]-k));
                pq.pop();
            }
            cout<<cost<<endl;
        }
    }
}