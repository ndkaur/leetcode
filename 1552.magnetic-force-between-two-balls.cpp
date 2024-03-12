/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
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
    bool isPossible(int mid, vector<int>& pos, int m){
        int  n= pos.size();
        int cnt = 1;
        int prev = pos[0];
        for(int i=1; i<n; i++){
            if(pos[i]-prev>=mid){
                cnt++;
                prev = pos[i];
            }
            if(cnt>=m)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end());
        int l = 1;
        int r = pos[n-1]-pos[0];
        int ans = 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            // given m <= cnt using the diff as the given mid is possible incre and check  
            if(isPossible(mid, pos, m)){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};


class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        int n= pos.size();
        sort(pos.begin(),pos.end());
        int l=1;
        int h= pos[n-1]-pos[0];
        while(l<=h){
            int mid= l+(h-l)/2;
            if(possible(pos,m,mid)==true){
                l=mid+1;
            }else 
                h= mid-1;
        }
        return h;
    }
    bool possible(vector<int>& pos,int m,int mid){
        int n= pos.size();
        int ball=1;
        int prev= pos[0];
        for(int i=1;i<n;i++){
            int curr= pos[i];
            if((curr-prev) >=mid){
                prev=curr;
                ball++;
            }
            if(ball==m)
                return true;
        }
        return false;
    }
}; // o(nlog m)


// @lc code=end


int main(){
    Solution sol;
    vector<int> pos={1,2,3,4,7};
    int m=3;
    int ans= sol.maxDistance(pos,m);
    cout<<ans;
    return 0;
}