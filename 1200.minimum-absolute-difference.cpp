/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> output;
        vector<int> temp;
        
        sort(arr.begin(),arr.end());

        int diffmn=INT_MAX;

        for(int i=1;i<arr.size();i++){
            diffmn=min(diffmn,(arr[i]-arr[i-1]));
        }

        for(int i=1;i<arr.size();i++){
            temp.clear();
            if(arr[i]-arr[i-1]==diffmn){
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                output.push_back(temp);
            }
        }
        return output;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> output;
    vector<int> arr={4,2,1,3};
    output=sol.minimumAbsDifference(arr);
    for(auto o:output){
        print(o);
    }
    return 0;
}