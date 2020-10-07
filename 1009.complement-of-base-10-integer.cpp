/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
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
    int bitwiseComplement(int N) {
        int x=1;
        while(N>x){
            x=x*2+1;
        }
        return x-N;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int N=10;
    int ans=sol.bitwiseComplement(N);
    cout<<ans;
    return 0;
}