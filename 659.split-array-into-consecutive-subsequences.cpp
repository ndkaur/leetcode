/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
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
    bool isPossible(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> freq; // total count of each num
        unordered_map<int,int> subseq; // count of subsequences ending at that num
        
        for(auto num:nums){
            freq[num]++;
        }
        // iterating on bais of num not idx 
        for(auto num:nums){
            if(freq[num]==0) // if we already sdded the num in the subseq then skip iteration for that move to next num
                continue;
            // if the seq already exist before the num , we can add the curr num to the exisiting subseq
            if(subseq[num-1]>0){
                freq[num]--;
                subseq[num-1]--;
                subseq[num]++;
            }
            // if no subseq already make a new subseq 
            else{
                if(freq[num+1]==0 || freq[num+2]==0)
                    return false;
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                subseq[num+2]++;
            }
        }
        return true;
    }
};

// @lc code=end


int main(){

    return 0;
}