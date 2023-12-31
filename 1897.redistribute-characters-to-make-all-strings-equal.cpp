/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
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

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n==1)
            return true;
        int cnt = 0;
        for(auto word:words){
            cnt += word.size();
        }
        if(cnt%n!=0 ) // if we cant divide total length in equal parts
            return false;
        vector<int> mp(26,0);

        for(auto word:words){
            for(auto ch:word){
                mp[ch-'a']++;
            }
        }

        for(int val:mp){
            if(val%n!=0) // if cant divide freq of each number into equal parts
                return false;
        }
        return true;
    }
};

// abc, aabc, bc  n=3
// total chars  = 9, 9%3==0 so possible
// a->3  3%3==0 so true 
// b-> 3
// c-> 3   


// @lc code=end


int main(){

    return 0;
}