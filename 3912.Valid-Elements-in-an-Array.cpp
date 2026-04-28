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
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums;

        vector<int> ans;
        
        vector<int> left(n,0);
        left[0]= nums[0];
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], nums[i]);
        }

        vector<int> right(n,0);
        right[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], nums[i]);
        }   
        
        ans.push_back(nums[0]);
        for(int i=1; i<n-1; i++){
            if(nums[i]>left[i-1] || nums[i]>right[i+1]){
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};


int main(){

    return 0;
}