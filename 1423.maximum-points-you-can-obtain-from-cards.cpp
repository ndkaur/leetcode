/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
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
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int sum =0;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }
        int curr = sum;
        for(int i= k-1; i>=0; i--){
            curr -= cardPoints[i]; // already added in prev window 
            curr +=  cardPoints[n-k+i];
            sum = max(sum,curr);
        }
        return sum; 
    }
};


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int l=0;
        int r = n-k;
        int curSum =0;

        for(int i=r; i<n; i++){
            curSum+= cardPoints[i];
        }

        int res = curSum;
        while(r<n){
            // adding the left val , subtracting the right val
            curSum += cardPoints[l];
            curSum -= cardPoints[r];
            res = max(res, curSum);
            l += 1;
            r += 1;
        }
        return res;
    }
};

// 1 2 3 4 5 6 1 
// _ _ _ _ * * *      * is our cur sum  = 5 + 6 + 1 = 12 

// shift the window 

// 1 2 3 4 5 6 1 
// * _ _ _ _ * *   cur sum = 12 - 5 + 1 = 8 

// shifting window 

// 1 2 3 4 5 6 1 
// * * _ _ _ _ *   cur sum = 8 - 6 + 2 = 4 

// shifting window 

// 1 2 3 4 5 6 1 
// * * * _ _ _ _   cur sum = 4 - 1 + 3  = 6 

// max of all is 12 so ans 



// @lc code=end


int main(){

    return 0;
}