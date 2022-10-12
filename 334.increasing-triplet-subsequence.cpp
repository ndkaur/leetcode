/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
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
// tle  O(n^3)
class Solution0 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=  nums.size();
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]<nums[j] && nums[j]<nums[k]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// cant use montonic increasing stack as in c=some cases it doesnot give right result 


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=  nums.size();
        // one < two < three 
        int one = INT_MAX;
        int two = INT_MAX;
        for(int i=0; i<n; i++){
            // find the one ->min val of all
            if(nums[i] < one)
                one = nums[i]; //new min val found 
            // find two 
            else if(one < nums[i] && nums[i]< two)
                two = nums[i];
            // find third num which will be greater than two 
            else if(two < nums[i])
                return true;
        }
        return false;
    }
};

// @lc code=end


int main(){

    return 0;
}