/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
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
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        // indexes which have variable bits like at some as 1 or 0 it weill always result in 0 
        // where all the bits in all nums inbetween are 1 the ans will be 1 
        // so keep on cnting till we dont get same bit , 
        // .. add that cnt again as the number of 0 behind the same num 
        while(left!=right){
            left = left>>1;
            right = right>>1;
            cnt++;
        }
        return left<<cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}