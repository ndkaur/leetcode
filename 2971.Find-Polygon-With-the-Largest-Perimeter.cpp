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
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        // [1,12,1,2,5,50,3]
        sort(nums.begin(), nums.end());
        //  1 1 2 3 5 12 50 
        long long sum = 0;
        for(auto num:nums){
            sum += num;
        }
        // condition is the longest edge < summ of all remaining edges
        for(int i=n-1; i>=2; i--){ // we atleast need 3 edges 
            sum -= nums[i];
            if(sum>nums[i]){ // valid edge
                return sum + nums[i]; // the area is fully valid 
            }
        }
        return -1;
    }
};

int main(){

    return 0;
}