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

// mle 
class Solution0 {
public:
    int solve(int idx, vector<int>& height, int brick, int ladder, vector<vector<int>>& dp){
        int n = height.size();
        if(idx==n-1)
            return 0;
        if(dp[brick][ladder]!=-1)
            return dp[brick][ladder];
        
        if(height[idx]>=height[idx+1]){
            // simply move 
            dp[brick][ladder] = 1+solve(idx+1, height, brick, ladder, dp);
        }
        else{
            int b=0;
            int l=0;
            if(brick >= height[idx+1]-height[idx]){
                b = 1+solve(idx+1, height, brick-(height[idx+1]-height[idx]), ladder, dp);
            }
            if(ladder>0){
                l = 1+ solve(idx+1, height, brick, ladder-1, dp);
            }

            dp[brick][ladder] = max(b, l);
        }

        return dp[brick][ladder];
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<vector<int>> dp(bricks+1, vector<int>(ladders+1, -1));
        return solve(0, heights, bricks, ladders, dp);
    }
};

// lazy greedy 
class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = h.size();
        priority_queue<int> pq;
        int i =0;

        for(; i<n-1; i++){
            if(h[i] >= h[i+1])
                continue;

            int diff = h[i+1] - h[i];
            if(diff<=bricks){ // use bricks if we have them
                bricks-=diff;
                pq.push(diff); // store diff incase we got a case where using brick was efficent instead of ladder
            } 
            else if(ladders>0){ // bricks are all used up only ladder left
                // check if using the brick that we used in past was a better option
                if(pq.size()){
                    int mx = pq.top(); // the max bricks we used in the past 
                    if(mx > diff){ // if our curr diff can be fullfilled using the past bricks we will use them and replace with ladder as if ladder was used in past 
                        // reviving the bricks back
                        bricks+= mx;
                        pq.pop();
                        // using the brick to fill up diff 
                        bricks-=diff;
                        pq.push(diff); // new bricks getting used are equal to diff 
                    }
                }
                ladders--;
            }
            else 
                break;   
       }
       return i;
    }
};






int main(){

    return 0;
}