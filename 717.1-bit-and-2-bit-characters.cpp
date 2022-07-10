/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
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
    bool isOneBitCharacter(vector<int>& bits) {
        int n= bits.size();
        int i;
        for(i=0;i<n-1;){
            if(bits[i]==0)
                i++;
            else if(bits[i]==1)
                i+=2;
        }
        if(i==n-1)
            return true;
        return false;
    }
};
// @lc code=end


int main(){

    return 0;
}