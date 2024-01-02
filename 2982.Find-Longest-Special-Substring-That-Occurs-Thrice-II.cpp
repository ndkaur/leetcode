#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int cnt =0;
        int last = s[0];
        unordered_map<char, vector<int>> mp; // char , all its consequitive occurence cnt 
        for(auto ch:s){
            if(ch==last){
                cnt++;
            }
            else{
                mp[last].push_back(cnt);
                cnt = 1;
                last = ch;
            }
        }
        mp[last].push_back(cnt);

        int ans = -1;
        for(auto [ch, freq]:mp){
            sort(freq.rbegin(), freq.rend()); // in decreaing order
            int sz = freq.size();
            if(sz>=1){ // eg {4} 
                ans =  max(ans, freq[0]-2); // max freq is at front of array
            }
            if(sz>=2){  // eg {5,3}  aaaaa_ _  _ aaa -> pair length = 3 
                ans = max(ans, min(freq[1], freq[0]-1)); // take the min freq , or reduce the max freq
            }
            if(sz>=3){ // { 5, 4, 3} 
                ans = max(ans, min(freq[2], min(freq[1], freq[0])));
            }
        }
        if(ans<=0)
            return -1;
        return ans;
    }
};

// occurence array 
// sz >= 1  eg {4} this means 4 same chars occur together ->eg aaaa in that we want 
// those subsequence that occur thrice eg-> aaa then ans = 1 we take single a
// eg -> aaaa -> ans = 2 , we take aa , aa, aa so conclusion is max-2

// sz>=2 eg-> {3,4}

int main(){

    return 0;
}