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
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxp = (nums[i]-1)*(nums[j]-1);
                ans=max(ans,maxp);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,7};
    int ans= sol.maxProduct(nums);
    cout<<ans;
    return 0;
}