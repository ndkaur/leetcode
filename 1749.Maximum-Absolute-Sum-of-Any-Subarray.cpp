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

class Solution0 { // brute force  // O(n^2)
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            int mx = 0;
            for(int i=0; i<n; i++){
                int sum = 0;
                for(int j=i; j<n; j++){
                    mx = max(abs(sum), mx);
                    sum+=nums[j];
                }
            }
            return mx;
        }
    };
    
    // we can use kadens algo 
    // one kaden to find max subarray sum
    // another kaden to find min subarray sum
    class Solution1 { 
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            int mx = 0;
            int curSum  = 0;
            for(int i=0; i<n; i++){
                curSum += nums[i];
                mx= max(mx, curSum);
                curSum = max(curSum,0);
            }
    
            curSum = 0;
            int mn = INT_MAX;
            for(int i=0; i<n; i++){
                curSum += nums[i];
                mn = min(mn, curSum);
                curSum = min(curSum, 0);
            }
    
            return max(mx, abs(mn));
        }
    };
    
    // using only single kaden by kading orginal array , and reversing the signs for next iteration
    class Solution {  // O(N) size of the array 
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size();
            int mx_sum = kaden(nums);
            // reversing the signs to find the min subarray sum using kaden algo
            for(int i=0; i<n; i++){
                nums[i] = -1*nums[i];
            }
            int mn_sum = kaden(nums);
            return max(mx_sum, abs(mn_sum));
        }
        int kaden(vector<int>& nums){
            int mx = 0;
            int curSum = 0;
            for(int i=0; i<nums.size(); i++){
                curSum += nums[i];
                mx= max(mx, curSum);
                curSum = max(curSum,0);
            }
            return mx;
        }
    };
    


int main(){

    return 0;
}