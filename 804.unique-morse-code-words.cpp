/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> ans ;
        vector<string> morse ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto w:words){
            string s;
            for(auto c:w)
                s=s+ morse[c-'a'];
            ans.insert(s);
        }
        return ans.size();
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<string> words={"gin", "zen", "gig", "msg"};
    int len =sol.uniqueMorseRepresentations(words);
    cout<<len;
    return 0;
}