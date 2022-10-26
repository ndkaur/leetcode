/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        // sort the array
        int ans =0; 
        sort(intervals.begin(), intervals.end());
        // take one as prev and curr
        int prev=0; 
        for(int curr=1; curr<n; curr++){
            // overlaping 
            // case one when partially overlap ->{1,5} {3,6}  prev end > cur start  
            // we will delete the 3,6 
            if(intervals[prev][1] > intervals[curr][0]){ // delete curr but it automatically gets removed in curr for loop
                ans++;
                // case 2 when fully overlap ->{1,5}  {2,3}  prev end > curr end
                if(intervals[prev][1] > intervals[curr][1]){ // we delete {1,5} prev
                    prev = curr;
                }
            }
            // non overlap
            else{
                prev = curr;
            }
        }
        return ans;
    }
};  


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        int n = inv.size();
        sort(inv.begin(), inv.end());
        int cnt = 0;
        int j = 0;
        for(int i=1; i<n; i++){
            // overlap s1 <= e2   && e1 >= s2
            if(inv[j][1] > inv[i][0]){
                cnt++;
                // remove the interval that is max 
                //if our j interval is max remove it 
                if(inv[j][1] > inv[i][1]){
                    j = i;
                }
            }
            // not overlap 
            else{
                // then also ove the j ahead 
                j = i;
            }
        }
        return cnt;
    }
};
// @lc code=end




int main(){

    return 0;
}