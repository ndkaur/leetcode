/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
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

// tle
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //  0 1  2  3 4 5 6 7
        // [1,3,-1,-3,5,3,6,7] k =3
        int l = 0;
        int r = k-1;
        vector<int> ans;
        while(r<n){
            int mx = *max_element(nums.begin()+l,nums.begin()+r+1);
            ans.push_back(mx);
            l++;
            r++;
        }
        return ans;
    }
};

// o(nlogn)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //  0 1  2  3 4 5 6 7
        // [1,3,-1,-3,5,3,6,7] k =3
        // max heap with idx
        priority_queue<pair<int,int>> pq;
        // inserting first k in pq
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        vector<int> ans;
        // inserting the ans of the first window 
        ans.push_back(pq.top().first);
        // adding the remaining elements
        for(int i=k; i<n; i++){
            // check if all the elemts present in pq are in the valid range 
            // idx of elem in pq <= i-k  
            // let i = 3 , so not in range= i-k = 3-3 =0 
            // i= 4 , i-k = 4-3 = 1 remove idx 1
            while(pq.size() && pq.top().second<= i-k){
                pq.pop();
            }
            pq.push({nums[i], i}); // add new elemets
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// max heap
//  0 1  2  3 4 5 6 7
// [1,3,-1,-3,5,3,6,7], k = 3

// pq = (3,1) (1,0) (-1,2) 
//  ans = {3,}
// i=3 to remove = i-k =3-3 = 0  pq = (3,1) (-1,2) 
// insert pq = (3,1)  (-1,2) (-3,3)
//  ans = {3,3}
// i=4 to remove = i-k = 4-3 =1  pq = (-1,2) (-3,3)
// insert in pq  = (5,4) (-1,2) (-3,3)
//  ans= {3,3,5}
// i=5 to remove = i-k = 5-3 =2  pq=  (5,4) (-3,3)
// insert in pq = (5,4) (3,5) (-3,3)
//  ans= {3,3,5,5}
// i=6 to remove = i-k = 6-3 =3  pq = (5,4) (3,5) 
//insert in pq =  (6,6) (5,4) (3,5) 
//  ans= {3,3,5,5,6}
// i=7 to remove = i-k = 7-3 = 4  pq =  (6,6) (3,5) 
// insert in pq = (7,7)  (6,6)  (3,5) 
//  ans= {3,3,5,5,6,7}





// @lc code=end


int main(){

    return 0;
}