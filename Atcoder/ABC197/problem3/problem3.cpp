#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007
#define mp make_pair

ll fact[200005], a[20], check[20];

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

void Combination( int reqLen, int start, int currLen, int len, vector<int>&v) 
{
	// Return if the currLen is more than the required length.
	if(currLen > reqLen)
	return;
	// If currLen is equal to required length then print the sequence.
	else if (currLen == reqLen) 
	{
		//cout<<"\t";
		for (int i = 0; i < len; i++) 
		{
			if (check[i] == true) 
			{
				//cout<<a[i]<<" ";
				v.pb(a[i]);
			}
		}
		//cout<<"\n";
		return;
	}
	// If start equals to len then return since no further element left.
	if (start == len) 
	{
		return;
	}
	// For every index we have two options.
	// First is, we select it, means put true in check[] and increment currLen and start.
	check[start] = true;
	Combination( reqLen, start + 1, currLen + 1,  len, v);
	// Second is, we don't select it, means put false in check[] and only start incremented.
	check[start] = false;
	Combination(reqLen, start + 1, currLen,  len, v);
}


void solve(){
  ll n,m,i,j,x,y;
  cin>>n;
  ll ar[n];
  for(i=0;i<n;i++)cin>>ar[i];
  ll ans=0;
  //bool check[n-1];
	//int arr[n-1];
	set<int>s;
	for(i=0;i<n-1;i++){a[i]=i+1;check[i]=false;}
	for(i=0;i<n;i++){
	  if(i==0){
	    int k=0;
	    for(j=0;j<n;j++)k^=ar[j];
	    s.insert(k);
	    //cout<<k<<"\n";
	  }
	  else{
	    vector<int>v;
	    Combination(i, 0, 0, n-1, v);
	    int k=0,z=0;
	    //cout<<"lal"<<v.size()<<" ";
	    for(int l=0;l<v.size();l+=i){
	      vector<int>o;
	      //cout<<v[l]<<" ";
	      z=l;
	      k=0;
	      for(j=0;j<n;j++){
	        if(z>=l+i){
	          k|=ar[j];
	        }
	        else if(j<v[z]){
	          k|=ar[j];
	        }
	        else{
	          z++;
	          //cout<<k<<"\n";
	          o.pb(k);
	          k=ar[j];
	        }
	      }
	      //cout<<"lala"<<o.size()<<"\n";
	      o.pb(k);
	      k=0;
	      for(j=0;j<o.size();j++)k^=o[j];
	      s.insert(k);
	      //cout<<k<<"\n";
	    }
	  }
	}
	//cout<<s.size()<<" ";
	auto it=s.begin();
	ans = *it;
  cout<<ans<<"\n";
  //cout<<ans<<"\n";
  // cin>>n>>m>>x>>y;
  // string s[n];
  // for(i=0;i<n;i++)cin>>s[i];
  // ll ans=1;
  // for(i=y;i<m;i++){
  //   if(s[x-1][i]=='.')ans++;
  //   else break;
  // }
  // for(i=y-2;i>=0;i--){
  //   if(s[x-1][i]=='.')ans++;
  //   else break;
  // }
  // for(i=x;i<n;i++){
  //   if(s[i][y-1]=='.')ans++;
  //   else break;
  // }
  // for(i=x-2;i>=0;i--){
  //   if(s[i][y-1]=='.')ans++;
  //   else break;
  // }
  // cout<<ans<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  //cin>>t;
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  int x=1;
  while (t--){
    //cout << "Case #"<<x<<": ";
    x++;
    solve();
  }
  return 0;
}