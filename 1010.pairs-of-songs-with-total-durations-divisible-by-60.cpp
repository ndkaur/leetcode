/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
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
//in this case time complexitiy is more.
// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         int n= time.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i<j){
//                     if((time[i]+time[j])%60==0)
//                         count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n= time.size();
        vector<int> seen(60,0);
        int count=0;
        for(int i=0;i<n;i++){
            //value+req=60
            //req=60-value
            int value=time[i]%60;
            int req=(60-value)%60;
            count=count+seen[req];
            seen[value]++;
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> time={30,20,150,100,40};
    int res=sol.numPairsDivisibleBy60(time);
    cout<<res;
    return 0;
}