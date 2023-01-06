/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
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
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        int n = strs.size();
        int m = strs[0].size();
  
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                if(strs[i][j] < strs[i-1][j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

// c b a
// d a f
// g h i 

// @lc code=end


int main(){

    return 0;
}