/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
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
    int countBalls(int l, int h) {
        vector<int> count(46);
        for(int i=l;i<=h;i++){
            int sum=0;
            int n=i;
            while(n){
                sum+= n%10;
                n/=10;
            }
            count[sum]++;
        }
        return *max_element(count.begin(),count.end());
    }
};
// @lc code=end


int main(){
    Solution sol;
    int l=1;
    int h=10;
    int ans = sol.countBalls(l,h);
    cout<<ans;
    return 0;
}