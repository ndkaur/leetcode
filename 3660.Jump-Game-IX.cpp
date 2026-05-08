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
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev_max(n); // max
        vector<int>  next_min(n); // min
        vector<int> ans(n);

        prev_max[0] = nums[0];
        for(int i=1; i<n; i++){
            prev_max[i] = max(nums[i], prev_max[i-1]);
        }

        next_min[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            next_min[i] = min(nums[i], next_min[i+1]);
        }

        ans[n-1] = prev_max[n-1];
        for(int i=n-2; i>=0; i--){
            // prev_max>next_min
            if(prev_max[i]>next_min[i+1]){
                ans[i] = ans[i+1];
            }
            else{
                ans[i] = prev_max[i];
            }
        }
        return ans;
    }
};

// i->j = larger->small
// j<-i = small <- large

// i-1  i  i+1
// i-> i-1 = small->large (ascending)
// i->i+1 = large->small (descending) 

// 2->1 => 2 <- 1, inversion possible 
// large-> small ==  large <- small

// max prev > min next // valid
// max prev <= min next // invalid



int main(){

    return 0;
}