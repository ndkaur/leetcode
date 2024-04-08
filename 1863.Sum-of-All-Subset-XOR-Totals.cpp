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
    int f(int idx, int xorVal, vector<int>& nums){
        int n = nums.size(); 
        if(idx==n)
            return xorVal;
        int pick = f(idx+1, xorVal^nums[idx], nums);
        int npick = f(idx+1, xorVal, nums);
        return pick + npick;
    }
    int subsetXORSum(vector<int>& nums) {
        return f(0, 0 , nums);
    }
};


int main(){

    return 0;
}