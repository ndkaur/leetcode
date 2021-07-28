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
    int triangleNumber(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[j]+nums[k]>nums[i])
                        count++;
                }
            }
        }
        return count;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int k =i+2;
            for(int j=i+1 ; j<n-1 && nums[i]!=0 ; j++){
                while(k<n && nums[i]+nums[j]>nums[k])
                    k++;
                count += k-j-1;
            }
        }
        return count;
    }
};


int main(){
    Solution sol;
    vector<int> nums={2,2,3,4}; 
    int ans = sol.triangleNumber(nums);
    cout<<ans;
    return 0;
}