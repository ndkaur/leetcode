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


class Solution { // O(nlogn)
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // all +ve then take the max nums
        long long pro = (long long) nums[n-1] * nums[n-2] * 100000;
        // few -ve , then few +ve nums so take the -ve and max +ve 
        // -ve * +ve * -10^5 = +ve val max
        pro = max(pro , (long long)nums[0]*nums[n-1]* (-100000));
        // all -ve nums, then the first two nums will be high -ve values 
        pro = max(pro , (long long)nums[0]*nums[1]* 100000);
        return pro;
    }
};

// neg -> -4 -3 -2 -1 
// pos -> 1 2 3 4
//-5 0 7



int main(){

    return 0;
}