/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
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
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4 !=0)
                return false;
            n= n/4;
        }
        return n==1;
    }
};


// bits 
// pow of 4 only if 1 set bit present and its it at odd place
// 1 2 4 8 16 32 64 128 256 592 1084 ...... -> This All Are Power Of Two [ Mean Having Only One Set Bit ]
// 1 4 16 64 256 1084......-> This All Are Power Of Four , Now We can Greedly Observe
// That Between two power_of_4 there Was One Invaild Power_Of_4 Exist

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        int no_of_one =0;
        int pos = 1;
        int one_pos= 0;
        while(n){
            if(n & 1){// set bit 
                no_of_one += 1;
                one_pos = pos;
            }
            n>>=1;
            pos+=1;
        }
        return no_of_one ==1 && one_pos & 1;
    }
};
// @lc code=end



int main(){

    return 0;
}