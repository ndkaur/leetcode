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

class Solution0 {
public:
    int find(int target, vector<int>& nums, unordered_map<int,int>& mp, int k, int& numOperations){
        auto left = lower_bound(nums.begin(), nums.end(), target-k);
        auto right = lower_bound(nums.begin(), nums.end(), target+k+1);
        int cnt = (right-left) - mp[target];
        return min(cnt, numOperations)+mp[target];
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;

        for(int num:nums){
            mp[num]++;
        }
        
        int mx_elm = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<=mx_elm; i++){
            ans = max(ans, find(i, nums, mp, k, numOperations));
        }
        return ans;
    }
};


// intituation:-
// in nums array we for each num we have a range [num-k, num+k]
// and the max num [mx-k, mx+k] so 
// 1. we will keep on making targets one by one in range(1->mx)
// 2. for each target range is [targe-k, target+k] = [l,r]
// 3. we need to find how many operation will it take to make target but there is a possiblity that the target alredy exist in array and has a count so we need to subtract that cnt of target as why to waste operations on target
// we need freq array that will store accumultive cnt 
// 4. total cnt of range -> freq[r] - freq[l-1]
// 5. total cnt of target-> freq[target] - freq[targe-1]
// 6. required cnt =  total cnt of range - total cnt of target
// 7. final cnt = required cnt + freq of target
// 8. ans = max(ans, final cnt)

class Solution { // time comp-> O(maxval)
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int mx_elm = *max_element(nums.begin(), nums.end());
        int range_mx = mx_elm+k;

        vector<int> freq(range_mx+1,0);
        for(int num:nums){
            freq[num]++;
        }

        // making it cumulative sum of frequency 
        for(int i=1; i<=mx_elm; i++){
            freq[i]+= freq[i-1];
        }

        int ans =0;
        for(int target=0; target<=mx_elm; target++){
            if(freq[target==0])
                continue;
            
            int left = max(0, target-k);
            int right = min(mx_elm, target+k);

            int total_cnt = freq[right] - (left>0 ? freq[left-1]:0);
            int target_cnt = freq[target] - (target>0 ? freq[target-1]:0);
            int need = total_cnt-target_cnt;
            int mx_poss = target_cnt + min(need, numOperations);
            ans = max(ans, mx_poss);
        }
        return ans;
    }
};





int main(){

    return 0;
}