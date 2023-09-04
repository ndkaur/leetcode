/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
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
    bool judgeCircle(string moves) {
        int n = moves.size();
        int ud=0, rl=0;
        for(int i=0; i<n; i++){
            if(moves[i]=='U')
                ud++;
            else if(moves[i]=='D')
                ud--;
            else if(moves[i]=='R')
                rl++;
            else 
                rl--;
        }
        return (ud==0 && rl==0);
    }
};

// @lc code=end



int main(){

    return 0;
}