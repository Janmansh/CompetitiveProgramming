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

void makeCombiUtil(vector<vector<int> >& ans,
    vector<int>& tmp, int n, int left, int k)
{
    // Pushing this vector to a vector of vector
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
  
    // i iterates from left to n. First time
    // left will be 1
    for (int i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
  
        // Popping out last inserted element
        // from the vector
        tmp.pop_back();
    }
}
  
// Prints all combinations of size k of numbers
// from 1 to n.
vector<vector<int> > makeCombi(int n, int k)
{
    vector<vector<int> > ans;
    vector<int> tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}


void solve(){
  ll n,i,j,m,p;
  cin>>n>>m>>p;
  string s[n];
  for(i=0;i<n;i++)cin>>s[i];
  string ans = "";
  vector<int>ind;
  for(i=0;i<m;i++)ans.pb('0');
  for(i=0;i<m;i++){
    int c=0;
    for(j=0;j<n;j++){
      if(s[j][i] == '1')c++;
    }
    if(c>=(n+1)/2){
      //ans[i]='1';
      ind.pb(i);
    }
  }
  //for(i=0;i<ind.size();i++)cout<<ind[i]<<" ";
  //cout<<"\n";
  for(i=p;i>=1;i--){
    int x=0;
    if(i>ind.size())continue;
    vector<vector<int>>ind1 = makeCombi(ind.size(),i);
    
    // for(j=0;j<ind1.size();j++){
    //   for(int z=0;z<ind1[j].size();z++)cout<<ind1[j][z]<<" ";
    //   cout<<"\n";
    // }
    
    
    for(j=0;j<ind1.size();j++){
      int count=0;
      for(int z=0;z<n;z++){
        int c=1;
        for(int k = 0; k < ind1[j].size() ; k++){
          if(s[z][ind[ind1[j][k]-1]] == '0'){
            c=0;
            break;
          }
        }
        if(c)count++;
      }
      if(count>=(n+1)/2){
        //for(int z=0;z<m;z++)ans[z]='0';
        for(int z=0;z<ind1[j].size();z++)ans[ind[ind1[j][z]-1]]='1';
        x=1;
        break;
      }
    }
    if(x)break;
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  //srand(time(0));
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    solve();
  }
  return 0;
}