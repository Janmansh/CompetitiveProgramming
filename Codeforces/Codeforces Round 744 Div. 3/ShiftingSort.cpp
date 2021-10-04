#include<bits/stdc++.h>
using namespace std;
#define ll long long
//double pi = 3.1415926536;
#define  PB push_back
#define  MP make_pair
//long long mod = 1e6 + 3;




int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n); //vector with size n
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<vector<int> > ok;
		for (int i = 0; i < n; i++) {
			int itr = max_element(a.begin(), a.end()) - a.begin(); //*the position of the maximum element
			if (itr != n - i - 1) { //*here we are checking that our max element is last or not n-i-1 because array size will be changing as i progresses because we will delete max later
				ok.push_back({itr + 1, n - i, 1}); //*itr+1 because 0 based indexing and we have to give 1 based n-i last position as i progresses and 1 shift always
				//*this is how to push vector inside vector
			}
			a.erase(a.begin() + itr); //*deleting that element
		}
		cout << ok.size() << endl;
		for (auto it : ok) {
			cout << it[0] << " " << it[1] << " " << it[2] << endl;
		}
	}

	return 0;

}
