#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX_CHARS = 256; 
  
// Function to find smallest window containing 
// all distinct characters 
string findSubString(string str) 
{ 
    int n = str.length(); 
  
    // Count all distinct characters. 
    int dist_count = 0; 
    bool visited[MAX_CHARS] = { false }; 
    for (int i = 0; i < n; i++) { 
        if (visited[str[i]] == false) { 
            visited[str[i]] = true; 
            dist_count++; 
        } 
    } 
  
    // Now follow the algorithm discussed in below 
    // post. We basically maintain a window of characters 
    // that contains all characters of given string. 
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    int count = 0; 
    int curr_count[MAX_CHARS] = { 0 }; 
    for (int j = 0; j < n; j++) { 
        // Count occurrence of characters of string 
        curr_count[str[j]]++; 
  
        // If any distinct character matched, 
        // then increment count 
        if (curr_count[str[j]] == 1) 
            count++; 
  
        // if all the characters are matched 
        if (count == dist_count) { 
            // Try to minimize the window i.e., check if 
            // any character is occurring more no. of times 
            // than its occurrence in pattern, if yes 
            // then remove it from starting and also remove 
            // the useless characters. 
            while (curr_count[str[start]] > 1) { 
                if (curr_count[str[start]] > 1) 
                    curr_count[str[start]]--; 
                start++; 
            } 
  
            // Update window size 
            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    // Return substring starting from start_index 
    // and length min_len 
    return str.substr(start_index, min_len); 
} 

int main() 
{ 
    long long t,i;
    cin>>t;
    string s;
    while(t--){
    cin>>s;
    bool it[3]={false};
    for(i=0;i<s.length();i++){
      if(s[i]=='1'){
        it[0]=true;
      }
      if(s[i]=='2'){
        it[1]=true;
      }
      if(s[i]=='3'){
        it[2]=true;
      }
    }
    if(it[0]&&it[1]&&it[2]){
      string l= findSubString(s);
      cout<<l.length()<<endl;
    }
    else{
      cout<<"0"<<endl;
    }
    }
    return 0; 
} 