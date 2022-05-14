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
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }
        long long  count=0;
        long long t=0;
        for(int i=0;i<n-1;i++){
            t+= nums[i];
            if(t>=(sum-t))
                count++;
        }
        return count;
    }
};

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size();
        long long l=0;
        long long r=0;
        long long ans =0;
        for(int i=0;i<n;i++) r+=nums[i];
        for(int i=0;i<n-1;i++){
            l+=nums[i];
            r -= nums[i];
            ans+= (l>=r);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums={10,4,-8,7};
    int ans= sol.waysToSplitArray(nums);
    cout<<ans;
    return 0;
}