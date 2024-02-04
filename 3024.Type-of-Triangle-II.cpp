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
    string triangleType(vector<int>& nums) {
        int n=  nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]+nums[1]<=nums[2])
                return "none";
        if(nums[0]==nums[1] && nums[1]==nums[2])
                return "equilateral";
        if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2])
                return "isosceles";
        return "scalene";    
    }
};


int main(){

    return 0;
}