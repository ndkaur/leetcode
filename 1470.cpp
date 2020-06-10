#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> out;
        for(int i=0;i<n ;i++){
            out.push_back(nums[i]);
            out.push_back(nums[i+n]);
        }
        return out;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3,4,4,3,2,1};
    vector<int> out=sol.shuffle(nums,4);
    print(out);
    return 0;
}