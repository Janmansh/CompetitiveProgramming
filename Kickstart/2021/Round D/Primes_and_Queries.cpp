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
  if(x==0)return 0;
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

int getMid(int s, int e) { return s + (e -s)/2; }
 
/* A recursive function to get the sum of values in the given range
    of the array. The following are parameters for this function.
 
    st --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
            0 is passed as root is always at index 0
    ss & se --> Starting and ending indexes of the segment represented
                by current node, i.e., st[si]
    qs & qe --> Starting and ending indexes of query range */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes which have the given
index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i --> index of the element to be updated. This index is
            in the input array.
diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input";
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start)
// to qe (query end). It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
            constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
allocates memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for the segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
 
    // Allocate memory
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

void solve(){
  ll n,i,j,q,p;
  cin>>n>>q>>p;
  ll a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  int arr1[n],arr2[n],arr3[n],arr4[n];
  for(i=0;i<n;i++){
    int c=0;int x=a[i]-(a[i]%p);
    while(x and x%p==0){
      c++;
      x/=p;
    }
    arr1[i] = c;
  }
  for(i=0;i<n;i++){
    int c=0;int x=power(a[i],2)-power((a[i]%p),2);
    while(x and x%p==0){
      c++;
      x/=p;
    }
    arr2[i] = c;
  }
  for(i=0;i<n;i++){
    int c=0;int x=power(a[i],3)-power((a[i]%p),3);
    while(x and x%p==0){
      c++;
      x/=p;
    }
    arr3[i] = c;
  }
  for(i=0;i<n;i++){
    int c=0;int x=power(a[i],4)-power((a[i]%p),4);
    while(x and x%p==0){
      c++;
      x/=p;
    }
    arr4[i] = c;
  }
  // for(i=0;i<n;i++)cout<<arr1[i]<<" ";
  // cout<<"\n";
  // for(i=0;i<n;i++)cout<<arr2[i]<<" ";
  // cout<<"\n";
  // for(i=0;i<n;i++)cout<<arr3[i]<<" ";
  // cout<<"\n";
  // for(i=0;i<n;i++)cout<<arr4[i]<<" ";
  // cout<<"\n";
  ll t, ind, val, s, l, r;
  vector<int>answer;
  int *st1 = constructST(arr1, n);
  int *st2 = constructST(arr2, n);
  int *st3 = constructST(arr3, n);
  int *st4 = constructST(arr4, n);
  while(q--){
    cin>>t;
    if(t==1){
      cin>>ind>>val;
      ind--;
      a[ind] = val;
      int c=0;
      int x=a[ind] - (a[ind]%p);
      while(x and x%p==0){
        c++;
        x/=p;
      }
      updateValue(arr1, st1, n, ind, c);
      c=0;
      x=power(a[ind],2)-power((a[ind]%p),2);
      while(x and x%p==0){
        c++;
        x/=p;
      }
      updateValue(arr2, st2, n, ind, c);
      c=0;
      x=power(a[ind],3)-power((a[ind]%p),3);
      //if(ind==2)cout<<x<<"\n";
      while(x and x%p==0){
        c++;
        x/=p;
      }
      updateValue(arr3, st3, n, ind, c);
      c=0;
      x=power(a[ind],4)-power((a[ind]%p),4);
      while(x and x%p==0){
        c++;
        x/=p;
      }
      updateValue(arr4, st4, n, ind, c);
    }
    else{
      int ans=0;
      cin>>s>>l>>r;
      l--;
      r--;
      if(s==1)ans = getSum(st1, n, l, r);
      if(s==2)ans = getSum(st2, n, l, r);
      if(s==3)ans = getSum(st3, n, l, r);
      if(s==4)ans = getSum(st4, n, l, r);
      //ans*=s;
      // for(i=l;i<=r;i++){
      //   int x = power(a[i],s);
      //   x-=(power(a[i]%p, s));
      //   int v=0;
      //   while(x%p==0 and x){
      //     v++;
      //     x/=p;
      //   }
      //   ans+=v;
      // }
      answer.pb(ans);
    }
  }
  for(i=0;i<answer.size();i++)cout<<answer[i]<<" ";
  cout<<"\n";
  return;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll t=1;
  cin>>t;
  int x=1;
  //srand(time(0));
  // fact[0]=1;
  // for(int i=1;i<200001;i++){
  //   fact[i]=i*fact[i-1];
  //   fact[i]%=mod;
  // }
  while (t--){
    cout<<"Case #"<<x<<": ";
    solve();
    x++;
  }
  return 0;
}