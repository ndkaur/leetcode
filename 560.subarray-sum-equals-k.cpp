/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
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

class Solution0 { //O(n^2)
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        for(int i=0; i<n; i++){
            int sum = nums[i];
            if(sum==k)
                cnt++;
            for(int j=i+1; j<n; j++){
                sum += nums[j];
                if(sum==k)
                    cnt++;
            }
        }
        return cnt;
    }
};

// using prefix sum and map to store the sum

class Solution { //O(n) , O(n)
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        vector<int> prefix(n);
        prefix[0] =nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        // checking for sum alredy made in prefix array
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            if(prefix[i] == k)
                cnt++;

            // check if find in map
            if(mp.find(prefix[i]-k)!=mp.end()){ // found in map
               cnt += mp[prefix[i]-k];
            }
            // add in map
            mp[prefix[i]]++;
        }
        return cnt;
    }
};


// @lc code=end


int main(){

    return 0;
}