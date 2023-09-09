/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */
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

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i =0;
        int j=0;
        int sum = 0;
        int cnt =0;
        while(j<n){
            sum += arr[j];
            if(j-i+1 < k){
                j++;
            }
            else{
                if(sum/k >= threshold){
                    cnt++;
                }
                sum = sum-arr[i];
                i++;
                j++;
            }
        }
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}