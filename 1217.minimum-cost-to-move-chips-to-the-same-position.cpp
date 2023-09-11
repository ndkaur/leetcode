/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
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
    int minCostToMoveChips(vector<int>& position) {
        // i+2, i-2 
        // if i even i=2 , i=0 , i=4
        //  if i=3 odd , i=1 i=5 
        // even to even or odd to odd no cost
        int n = position.size();
        int even  =0;
        int odd =0;
        for(int i=0; i<n; i++){
            if(position[i]%2==0)
                even++;
            else 
                odd++;
        }
        return min(even, odd);
    }
};


// @lc code=end


int main(){

    return 0;
}