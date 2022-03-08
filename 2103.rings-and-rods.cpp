/*
 * @lc app=leetcode id=2103 lang=cpp
 *
 * [2103] Rings and Rods
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
    int countPoints(string rings) {
        int n= rings.size();
        vector<vector<bool>> count(10,vector<bool>(3));
        for(int i=0;i<n;i=i+2){
            int color= rings[i]=='R'? 0: (rings[i]=='G' ? 1 : 2);
            int index= rings[i+1]-'0';
            count[index][color] = true;
        }
        int ans=0;
        for(int i=0;i<10;i++){
            ans += count[i][0] && count[i][1] && count[i][2];
        }
        return ans;
    }
};

class Solution {
public:
    int countPoints(string rings) {
        int n= rings.size();

    }
};
// @lc code=end


int main(){
    Solution sol;
    string rings= "B0B6G0R6R0R6G9";
    int ans= sol.countPoints(rings);
    cout<<ans;
    return 0;
}