/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
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

class Solution { //O(log 3 n) base is 3
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
        while(n>1){
            if(n%3) return false;
            n= n/3;
        }
        return n==1;
    }
};

bool isPowerOfThree(int n) {
	if(n <= 1) return n == 1;
	return n % 3 == 0 && isPowerOfThree(n / 3);
}
// Time Complexity : O(log3(n))
// Space Complexity : O(log3(n))

// @lc code=end


int main(){

    return 0;
}