/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
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
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zero_cnt = 0;
        int one_cnt = 0;
        for(auto ch:s){
            if(ch == '1')
                one_cnt++;
            else
                zero_cnt++;
            // zerocnt tells us which is min either we flip all 1 or all 0
            zero_cnt = min(one_cnt,zero_cnt);
        }
        return zero_cnt;
    }
};

// 0 0 1 1 0
// zcnt = 1, min(0,1)= 0, 2-> min(2,0)= 0 , 1 ->(1,2) = 1 
// ocnt = 0, 1 , 2 
// this means that if we flip one we get 2 as answer
// and if we flip all zeros we get 1 as answer 
// so 1 is min so we flip all zeroes 





// @lc code=end


int main(){

    return 0;
}