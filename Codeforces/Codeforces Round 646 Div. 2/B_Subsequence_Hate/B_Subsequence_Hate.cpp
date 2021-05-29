#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long n=s.size();
        long long z=0,o=0;
        long long c=0,i;
        for(i=0;i<s.size();i++){
            if (s[i]=='0')
                z++;
            else
                o++;
            
            if (i && s[i]!=s[i-1]){
                c++;
            }}
        if (c<=1)
            cout <<0<< endl;
        else{
            long long sum=0;
            long long answer=100000000;
            for (i=0;i<n;i++){
                if (s[i]=='1')
                    sum++;
                long long one=sum;
                long long zero=i+1-sum;
                
                long long bb=min(one,zero);
                one=o-sum;
                zero=n-(i+1)-one;
                bb+=min(one,zero);
                answer=min(answer,bb);
            }
            cout << answer << endl;
        }
        
    }
    
    return 0;
}