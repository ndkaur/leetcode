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
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums={3,1,2,10,1};
    vector<int> ans=sol.runningSum(nums);
    print(ans);
    return 0;
}