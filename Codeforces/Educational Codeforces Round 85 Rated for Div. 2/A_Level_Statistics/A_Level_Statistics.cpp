#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,i,j,l;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n][2];
		for(i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1];
		}
		for(i=0;i<n;i++){
			if(a[i][0]<a[i][1]){
				printf("NO\n");
				goto s;
			}
		}
		l=a[0][0]-a[0][1];
		for(i=1;i<n;i++){
			if((a[i][0]-a[i][1])<l){
				printf("NO\n");
				goto s;
			}
			l=(a[i][0]-a[i][1]);
		}
		for(i=1;i<n;i++){
			if((a[i][0]<a[i-1][0])||(a[i][1]<a[i-1][1])){
				printf("NO\n");
				break;
			}
		}
		s:
		if(i==n){
			printf("YES\n");
		}
	}
}
