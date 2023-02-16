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

// tle 
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n= nums.size();
        long long cnt =0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i]+ nums[j];
                if(sum >= lower && sum <= upper)
                    cnt++;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long ans = 0;
            // low <= nums[i]+nums[j] <= high
            // low -nums[i] <= nums[j] <= high -nums[i]
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            int x = lower - nums[i];
            int y = upper - nums[i];
            auto l = lower_bound(nums.begin()+i+1, nums.end(), x);
            auto h = upper_bound(nums.begin()+i+1, nums.end(), y);
            ans += h-l;
        }
        return ans;
    }
};

int main(){

    return 0;
}