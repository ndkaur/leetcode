/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */
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

// @lc code=start

//  same as lis , find the difference in chars between two words
class Solution {  // time -> O(n*n + lenght of string is )+ O(nlogn)  // space-> O(n)
public:
    bool checkPossible(string& s1, string& s2){
        if(s1.size()!= s2.size() +1) return false; // diff of 1 amoung sizes 
        int first=0;
        int second=0;
        while(first< s1.size()){
            if(s1[first]== s2[second]){
                first++;
                second++;
            } 
            else {
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }

    static bool compf(string& s1 , string& s2){
        return s1.size() < s2.size(); // increasing order on basis of size
    }

    int longestStrChain(vector<string>& words) {
        int n= words.size();
        sort(words.begin(),words.end(),compf);
        vector<int> dp(n,1);
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkPossible(words[i], words[j]) && 1+ dp[j]> dp[i]){
                    dp[i]= 1+ dp[j];
                }
            }
            if(dp[i]>mx) 
                mx= dp[i];
        }
        return mx;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<string> words={"a","b","ba","bca","bda","bdca"};
    int ans = sol.longestStrChain(words);
    cout<<ans;
    return 0;
}