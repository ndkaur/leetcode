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
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int last = -1;
        // n = 3, words = ["e","a","b"], groups = [0,0,1]
        // Output: ["e","b"]
         // n = 4, words = ["a","b","c","d"], groups = [1,0,1,1]
        //  output : ["a","b","c"] 
        for(int i=0; i<n; i++){
            if(groups[i]!=last){
                ans.push_back(words[i]);
                last =groups[i];
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}