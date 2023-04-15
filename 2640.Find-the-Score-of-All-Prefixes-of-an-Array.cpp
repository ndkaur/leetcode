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
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        long long mx = nums[0];
        for(int i=0; i<n; i++){
            // *max_element(nums.begin(),nums.begin()+i+1);
            mx = max(mx,(long long)nums[i]);
            long long curr = nums[i] + mx;
            if(ans.size()==0)
                ans.push_back(curr);
            else{
                ans.push_back(ans.back()+curr);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}