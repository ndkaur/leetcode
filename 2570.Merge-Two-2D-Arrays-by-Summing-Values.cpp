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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        // nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
        vetcor<vector<int>> ans;
        map<int,int> mp;
        for(auto num:nums1){
            mp[num[0]] += num[1];
        }
        for(auto num:nums2){
            mp[num[0]] += num[1];
        }
        for(auto m:mp){
            ans.push_back({m.first, m.second});
        }
        return ans;
    }
};



int main(){

    return 0;
}