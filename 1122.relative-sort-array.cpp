/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n= arr1.size();
        map<int,int> count;
        vector<int> ans;
        // for counting the occurence of each no
        for(auto i:arr1){
            count[i]++;
        }
        // for inserting the counted nos in ans list according to the order of arr2
        for(auto i:arr2){
            ans.insert(ans.end(),count[i],i);
            count[i]=0;
        }
        // for adding the reamining elements in ans list
        for(auto itr:count){
            int i=itr.first;
            int cnt=itr.second;
            ans.insert(ans.end(),cnt,i);
            
        }
        return ans;

    }
};
// @lc code=end
int main(){
    Solution sol;
    vi ans,arr1={2,3,1,3,2,4,6,7,9,2,19},arr2={2,1,4,3,9,6};
    ans=sol.relativeSortArray(arr1,arr2);
    print (ans);
   
    return 0;
}