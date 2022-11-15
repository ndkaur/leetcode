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
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i+1] = 0;
                nums[i] = nums[i]*2;
            }
            if(nums[i] == 0)
                cnt++;
        }
        if(nums[n-1] == 0)
            cnt++;
        vector<int> ans;
        for(auto num:nums){
            if(num>0){
                ans.push_back(num);
            }
        }
        while(cnt--){
            ans.push_back(0);
        }
        return ans;
    }
};

int main(){

    return 0;
}