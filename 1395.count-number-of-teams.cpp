/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
//O(n3)
class Solution0 {
public:
    int numTeams(vector<int>& rating) {
        int n= rating.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                for(int k=0;k<j;k++){
                    if(rating[i]<rating[j] && rating[j]<rating[k] || rating[i]>rating[j] && rating[j]>rating[k])
                        count++;
                }
            }
        }
        return count;
    }
}; // time limit exceeded


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count=0;
        for(int i=0;i<n;i++){
            int inc1=0,inc2=0,dec1=0,dec2=0;
            for(int j=0;j<n;j++){
                if(i>j){
                    if(rating[i]>rating[j])
                        dec1++;
                    else 
                        inc1++;
                }
                else if(j>i){
                    if(rating[j]>rating[i])
                        inc2++;
                    else 
                        dec2++;
                }
            }
            count += dec1*inc2 + inc1*dec2;
        }
        return count;
    }
};


// @lc code=end

int main(){
    Solution sol;
    vector<int> rating ={2,5,3,4,1};
    int ans = sol.numTeams(rating);
    cout<<ans;
    return 0;
}