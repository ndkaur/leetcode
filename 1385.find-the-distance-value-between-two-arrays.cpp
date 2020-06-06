/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        // for every value of i count only that value of j whose abs with all 
        // give back all greater numbers than d.

        int count =0;
        for(int i=0;i<arr1.size();i++){
            bool count_krna = true;

            for(int j=0;j<arr2.size();j++){
                int val=abs(arr1[i]-arr2[j]);
                if(val<=d)
                    count_krna = false;
            }
            if(count_krna) ++count;
        }
        return count;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> arr1={4,-3,-7,0,-10},arr2={10};
    int count=sol.findTheDistanceValue(arr1,arr2,69);
    cout<<count;
    return 0;
}