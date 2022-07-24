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
    long long zeroFilledSubarray(vector<int>& nums) {
        int n= nums.size();
        long long cnt=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
                ans+=cnt;
            }
            else    
                cnt=0;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums={0,0,0,2,0,0};
    int ans= sol.zeroFilledSubarray(nums);
    cout<<ans;
    return 0;
}