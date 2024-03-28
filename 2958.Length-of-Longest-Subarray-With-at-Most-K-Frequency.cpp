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
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int l = 0;
        int r = 0;
        int mx = 0;
        while(r<n){
            mp[nums[r]]++;
            while(l<r && mp[nums[r]]>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                    mp.erase(nums[l]);
                l++;
            }
            mx = max(mx, r-l+1);
            r++;
        }
        return mx;
    }
};

int main(){

    return 0;
}