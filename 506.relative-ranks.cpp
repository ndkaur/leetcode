/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
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
class Solution { //O(nlogn )
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n= score.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        //(10,0) (9,3) (8,2) (4,4) (3,1)
        vector<string> ans(n,"");
        int cnt=0;
        while(!pq.empty()){
            ans[pq.top().second]= cnt==0 ? "Gold Medal": cnt==1 ? "Silver Medal" : cnt==2 ? "Bronze Medal"  : to_string(cnt+1);
            cnt++;
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> score={10,3,9,8,4};
    vector<string> ans= sol.findRelativeRanks(score);
    for(auto c:ans)
        cout<<c<<endl;
    return 0;
}