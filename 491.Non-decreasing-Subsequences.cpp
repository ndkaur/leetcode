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

// similar to find number of subsets 

// Time Complexity : O(2^N * N^2)  -> 2^N for number of subset finding 
// Space Complexity : O(2^N * N) 

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans; // to remove dupilcate vectors generated 
        vector<int> temp;
        f(0,nums,temp, ans);
        return vector(ans.begin(), ans.end()); // typecasting set as vector
    }
    void f(int idx, vector<int>& nums, vector<int>& temp, set<vector<int>>& ans){
        int n = nums.size();
       
        if(idx >= n){
            if(temp.size() >= 2){
                ans.insert(temp);
            }
            return;
        }
        // empty temp  or increasing conditon 
        if(!temp.size() || nums[idx] >= temp.back()){
            temp.push_back(nums[idx]);
            f(idx+1, nums, temp, ans); // pick 
            temp.pop_back(); // backtrack 
        }
        // not pick 
        f(idx+1, nums, temp, ans);
    }
};

int main(){

    return 0;
}