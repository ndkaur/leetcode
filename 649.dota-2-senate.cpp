/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
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


class Solution {
public:
    string predictPartyVictory(string senate) {
        int  n = senate.size();
        queue<int> q1,q2;
        for(int i=0; i<n; i++){
            if(senate[i] == 'R')
                q1.push(i);
            else 
                q2.push(i);
        }
        // q1= R
        // q2 = D
        while(!q1.empty() && !q2.empty()){
            int r = q1.front();
            int d = q2.front();
            q1.pop();
            q2.pop();
            if(r < d)
                q1.push(r+n);
            else    
                q2.push(d+n);
        }

        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
};

int main(){

    return 0;
}
// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        
    }
};
// @lc code=end

