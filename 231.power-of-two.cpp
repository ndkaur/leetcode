/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
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

class Solution { // o(logn)
public:
    bool isPowerOfTwo(int n) {
        while(n>1){
            if(n%2)
                return false;
            n= n/2;
        }
        return n==1;
    }
};

// multiples of 2 only have 1 set bit 
class Solution { // o(1)
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int no_of_one = 0;
        while(n){
            if(n & 1){
                no_of_one += 1;
            }
            n>>=1;
        }
        return no_of_one == 1;
    }
};


// @lc code=end


int main(){

    return 0;
}