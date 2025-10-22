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



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int mx_val = *max_element(nums.begin(), nums.end());
        int mx_range =  mx_val+k;
        // to store freq of all ranges [num-k, num+k]
        map<int,int> mp; 
        // to store freq of the targets ie the num in nums array 
        unordered_map<int,int> freq;

        // O(nlogn)
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
            int l = max(nums[i]-k,0);
            int r = min(nums[i]+k, mx_range);

            // inserting the nums in range in map  and the original arrynums also in map 
            mp[l]++;
            mp[r+1]--;
            // orignal nums can also be possible target
            mp[nums[i]]+=0;
        }

        int ans = 0;
        int sum = 0; //to accumulate the sum in map 
        //O(N)
        for(auto itr:mp){
            int target = itr.first;
            itr.second += sum;

            int total_cnt = itr.second;
            int target_cnt = freq[target]; // num that exist in array 
            int need = total_cnt - target_cnt;
            int possible = min(need, numOperations);
            int required = possible + target_cnt;
            ans = max(ans,required);
            sum = itr.second;
        }
        return ans;
    }
};

// in its part1 we were using a accumulative freq array whose len was max elem 
// but here the constraints are very high so making that array will give tle 
// instead we use map to store only the required ranges 



int main(){

    return 0;
}