/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++){
        //    ans[i]=ans[i/2]+ i%2; // method 1
        //    ans[i] = ans[i&(i-1)]+1; // method2
            if(i%2==0)
                ans[i] = ans[i/2];
            else 
                ans[i] = ans[i/2]+1; // method 3
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int num=5;
    vector<int> ans =sol.countBits(num);
    print(ans);
    return 0;
}