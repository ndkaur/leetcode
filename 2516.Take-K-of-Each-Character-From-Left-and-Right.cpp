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


// s = "aabaaaacaabc", k = 2 ,
// "aaaacaabc"  = 3  , a=2, 1=b
// "aaaa"  = 5 , c=2, a=2, 1=b


class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        // sliding window with the map
        vector<int> cnt(3,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        if(cnt[0]<k || cnt[1]<k || cnt[2]<k)
            return -1;
        
        int mx = 0;
        int i =0;
        int j =0;
        vector<int> curr(3,0);

        while(j<n){
            curr[s[j]-'a']++;

            // slide the window when-> currcnt > totalcnt- k
            while(curr[0] > cnt[0]-k ||  curr[1] > cnt[1]-k || curr[2] > cnt[2]-k){
                curr[s[i]-'a']--;
                i++;
            }
            
            mx = max(mx, j-i+1);
            j++;
        }
        return n-mx;
    }
};


int main(){

    return 0;
}