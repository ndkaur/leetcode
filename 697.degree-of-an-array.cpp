#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int> cnt;
        for(auto x:nums) 
            cnt[x]++;
        int degree = 0;
        for(auto &p: cnt){
            if(p.second>degree){
                degree = p.second;
            }
        }
        
        map<int,int> first, last; // save idx
        for(int i=0;i<n;i++){
            if(!first.count(nums[i])){
                first[nums[i]] = i;
            }
            last[nums[i]] = i;
        }

        int ans = n;
        for(auto x: nums){
            if(cnt[x]==degree){
                int cur_len = last[x] - first[x] + 1;
                ans = min(ans, cur_len);
            }
        }

        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums={1,2,2,3,1};
    int ans=sol.findShortestSubArray(nums);
    cout<<ans;
    return 0;
}