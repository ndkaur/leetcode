#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n =nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(nums[i]==nums[j] && i<j){
                    count++;
                }
            }
        }
        return count;
    }
};


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int cnt =0;
        for(auto itr:mp){
            int val = itr.second;
            cnt += (val* (val-1)/2);
        }
        return cnt;
    }
};


int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    int count=sol.numIdenticalPairs(nums);
    cout<<count;
    return 0;
}