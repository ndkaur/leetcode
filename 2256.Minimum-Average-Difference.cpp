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
    int minimumAverageDifference(vector<int>& nums) {
        int n= nums.size();
        int mn = INT_MAX;
        int idx;
        long long sumFront=0;
        long long sumEnd=0;
        for(auto num:nums)
            sumEnd+= num;
        for(int i=0;i<n;i++){
            sumFront+= nums[i];
            sumEnd -= nums[i];
            int a= sumFront / (i+1);
            int b= (i==n-1) ? 0: sumEnd/ (n-i-1);

            if(abs(a-b)<mn){
                mn= abs(a-b);
                idx=i;
            }
        }
        return idx;
    }
};


int main(){
    Solution sol;
    vector<int> nums={2,5,3,9,5,3};
    int ans= sol.minimumAverageDifference(nums);
    cout<<ans;
    return 0;
}