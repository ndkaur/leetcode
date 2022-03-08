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
    int mostFrequent(vector<int>& nums, int key) {
        int n= nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++){
            if(nums[i]==key)
                mp[nums[i+1]]++;
        }
        int mx= INT_MIN;
        int target=-1;
        for(auto &it :mp){
            if(it.second > mx){
                mx= it.second;
                target= it.first;
            }
        }
        return target;
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,2,2,2,3};
    int key=2;
    int ans= sol.mostFrequent(nums,key);
    cout<<ans;
    return 0;
}