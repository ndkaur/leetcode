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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0; // max freq = that number of unique rows
        for(auto num:nums){
            mp[num]++;
            cnt = max(cnt, mp[num]);
        }

        vector<vector<int>> ans(cnt);
        for(auto itr:mp){
            int num = itr.first;
            int freq = itr.second;
            // enter the number in each seperate row 
            for(int i=0; i<freq; i++){
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};

// 1 1 1 2 3 3 4
// 1 2 3 4
// 1 3
// 1


int main(){

    return 0;
}