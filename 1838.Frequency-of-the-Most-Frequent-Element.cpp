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
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        int j=0;
        int ans =1;
        long sum =0;
        while(j<n){
            sum += nums[j];
            // if not valid -> sum + k < nums[j] * window length 
            while(sum + k < (long)nums[j] * (j-i+1)){
                sum =  sum - nums[i];
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

// [1,2,4], k = 5   => 3
// [1,4,8,13], k = 5  => 2
// [3,9,6], k = 2   => 1

int main(){

    return 0;
}