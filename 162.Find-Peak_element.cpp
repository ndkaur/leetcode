#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

class Solution0 {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                return i;
        }
        return n-1;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        return search(nums,0,n-1);
    }
    int search(vector<int>& nums, int l, int r){
        if(l==r)
            return l;
        int mid= (l+r)/2;
        if(nums[mid]>nums[mid+1])
            return search(nums, l, mid);
        return search(nums, mid+1,r);
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,1,3,5,6,4};
    int ans = sol.findPeakElement(nums);
    cout<<ans;
    return 0;
}