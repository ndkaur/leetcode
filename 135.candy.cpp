/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
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

//  greedy approach -> fill two arrays one from left to right with condition 
//  other from right to left with condition .. find the max of both arrays and add to sum 

class Solution {  // tc->O(n)  sc-> o(n)
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        // left to right increasing rder 
        vector<int> left(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i])
                left[i]= 1+ left[i-1];
        }
        //  right to left increasing order 
        vector<int> right(n,1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1] < ratings[i])
                right[i]= 1+ right[i+1];
        }
        int ans=0;
        for(int i=0;i<ratings.size();i++){
            ans+= max(left[i],right[i]);
        }
        return ans;
    }
};


class Solution { //O(N)
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // at any paticular idx check its left and right side 
        // search for if the curr idx is havig greater value than its neighbrour 
        vector<int> candies(n,1); // each should get atleat 1 candie
        // left neighbrour , i==0 no left neighb
        for(int i=1; i<n; i++){
            // we will only chnge if the curr idx val is greter than it left neig
            if(ratings[i]>ratings[i-1]){
                candies[i] = 1+candies[i-1]; // 1 more it will have 
            }
        }
        // right neigh lat idx i=n-1 no right neighbo
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        // now total sum
        int sum =0;
        for(int candie:candies){
            sum += candie;
        }
        return sum;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> ratings= {1,0,2};
    int ans = sol.candy(ratings);
    cout<<ans;
    return 0;
}