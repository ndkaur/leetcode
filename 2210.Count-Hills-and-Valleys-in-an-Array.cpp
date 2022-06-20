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
    int countHillValley(vector<int>& nums) {
        int n= nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
                v.push_back(nums[i]);
        }
        int count=0;
        
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1] || v[i]<v[i-1] && v[i]<v[i+1]){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,4,1,1,6,5};
    int ans= sol.countHillValley(nums);
    return 0;
}