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
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int idx = 0;
        for(int i=nums[0]; i<=nums[n-1]; i++){
            if(idx<n && nums[idx]==i)
                idx++;
            else 
                ans.push_back(i);
        }
        return ans;
    }
};


int main(){

    return 0;
}