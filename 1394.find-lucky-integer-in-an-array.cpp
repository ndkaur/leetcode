/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
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
    int findLucky(vector<int>& arr) {
        map<int,int> cnt;
        int out=INT_MIN;
        for(int i=0;i<arr.size();i++){
            cnt[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==cnt[arr[i]])
                out=max(arr[i],out);
            if(out==INT_MIN)
                return -1;
            else
                return out;
        }
       return out;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={2,1,3,4} ;
    int output=sol.findLucky(arr);
    cout<<output;
    return 0;
}