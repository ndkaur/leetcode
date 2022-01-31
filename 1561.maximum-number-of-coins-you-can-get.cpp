/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
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
    int maxCoins(vector<int>& piles) {
        int n= piles.size();
        sort(piles.begin(),piles.end());
        // 1 2 3  4 5 6  7 8 9 -> 9 8 1  7 6 2  5 4 3 
        // 1 2 2  4 7 8 -> 8 7 1  4 2 2    
        int sum=0;
        int i=0, k=n-1, j=k-1;
        while(i<j){
            sum+=piles[j];
            k=k-2;
            j=j-2;
            i++;
        }
        return sum;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> piles={9,8,7,6,5,4,3,2,1};
    int ans = sol.maxCoins(piles);
    cout<<ans;
    return 0;
}