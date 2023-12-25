/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
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
    int minOperations(string s) {
        int n = s.size();
        int cnt=0;
        // 0 1 2 3 4 5   do %2 then
        // 0 1 0 1 0 1  so condition becomes 
        // if index%2 == s[i] no cnt change  order is correct 
        // even odd even odd even odd 
        for(int i=0; i<n; i++){
            if(s[i]-'0'!=i%2)
                cnt++;
        }
        // but the order can be like 1 0 1 0 so in that case cnt will become the size of string ie n in that case answer will ne n-cnt = 0 ie no change required 
        return min(cnt, n-cnt);
    }
};

// 1111 -> cnt=0
// 1, i=0  => 1!=0 cnt =1
// 1 , i=1 => 1==1 
// 1, i=2 => 1!=0 , cnt=2
// 1, i=3 => 1==1 
// so return cnt = 2  

// 0100 -> cnt = 0
// 0 , i=0
// 1 , i=1
// 0 , i=2 
// 0 , i=3 => 0!=3%2  cnt++ 

// @lc code=end


int main(){

    return 0;
}