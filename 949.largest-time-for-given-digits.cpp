/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string result;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(i==j || j==k || k==i) continue;
                    string hh= to_string(A[i])+to_string(A[j]);
                    string mm= to_string(A[k])+ to_string(A[6-i-j-k]);
                    string time =hh+":"+mm;
                    if(hh<"24" && mm<"60" && time>result)
                        result=time;
                }
            }
        }
        return result;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> A={1,2,3,4};
    string ans=sol.largestTimeFromDigits(A);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}