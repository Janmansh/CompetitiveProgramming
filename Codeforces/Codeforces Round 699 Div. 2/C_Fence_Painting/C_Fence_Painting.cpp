#include<bits/stdc++.h>
using namespace std;
// Note: Policy based works only for sets (and not multisets)
// If you feel the need to use PBDS, always think of trying Fenwick Trees (VVIP) 
// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;   

#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
//#define ll long long
#define int long long
int ceil(int a, int b)
{
    return (a + b - 1)/b;
}
#define all(x)   (x).begin(),(x).end()
typedef pair<int, int> pi;
typedef tuple<int, int, int> tii;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf 1e18
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9; 
const int N = 3e5 + 2;


void SOLVE()
{
    int n, m;
    cin >> n >> m;
    vector<int> va(n), vb(n), vc(m);
    for(int i = 0; i < n; i++)
        cin >> va[i];
    for(int i = 0; i < n; i++)
        cin >> vb[i];
    for(int i = 0; i < m; i++)
        cin >> vc[i];

    // definitely needed 
    map<int, int> mp;
    vector<stack<int>> to_paint(n + 3);
    map<int, int> same, res;
    for(int i = 0; i < n; i++)
    {
        if(vb[i] != va[i])
        {
            mp[vb[i]]++;
            to_paint[vb[i]].push(i);
        }
        else
        {
            same[vb[i]] = i;
        }
    }

    int used = -1;

    for(int i = m - 1; i >= 0; i--)
    {
        int col = vc[i];
        //cout << i << " " << col << endl;

        if(mp.find(col) != mp.end() && mp[col] != 0 && !to_paint[col].empty())
        {
            //cout << "Painting i " << i << " " << to_paint[col].top() << endl;
            res[i] = to_paint[col].top();
            used = to_paint[col].top();
            same[col] = to_paint[col].top();
            to_paint[col].pop();
            mp[col]--;
            if(mp[col] == 0)
            {
                mp.erase(col);
            }
            
        }

        else
        {
            
            if(same.find(col) != same.end())
            {
                //cout << "Painting i " << i << " ........ " << same[col] << endl;
            
                used = same[col];
                res[i] = same[col];
                continue;
            }
            
            if(used == -1)
            {
                cout << "NO\n";
                return;
            }
            //cout << "Painting i " << i << " ..... " << used << endl;
            
            res[i] = used;
        }
    }
    bool poss = true;
    for(auto e: mp)
    {
        if(e.second != 0)
            poss = false;
    }
    if(!poss || res.size() != m)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto e: res)
    {
        cout << e.second + 1 << " ";
    }
    cout << "\n";
}
    
    
 
int32_t main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  sal = 0, ii, jj,x, y, l, r;
    int  i, j, q;
    int mn = INT_MAX, mx = INT_MIN;
 
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++)
    {
        //cout << "Case #" << I << ": ";
        SOLVE();
    }
}