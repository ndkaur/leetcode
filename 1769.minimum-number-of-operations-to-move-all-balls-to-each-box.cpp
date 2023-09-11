/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
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
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        
        vector<int> ones; // store the indexes of 1 in arr
        // boxes = [1,1,0] 
        // ones = [0,1]
        //  ans[0]= 0-0 + (0-1) = 1
        //  ans[1] = 1-0 + 1-1 = 1
        // ans[2] = 2-0 + 2-1 = 2+1 = 3
        for(int i=0; i<n; i++){
            if(boxes[i]=='1'){
                ones.push_back(i);
            }
        }
        
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<ones.size(); j++){
                ans[i] += abs(i-ones[j]);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}