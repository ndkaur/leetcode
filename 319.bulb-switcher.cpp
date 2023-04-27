/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
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

// for i th bulb in the j th round will be toggled
// if it is a factor ie if j is a factor of i 
// eg -> int round j = 2 only bulb ith  = 2, 4 ,6 will be toggled
// and if the number of factors are odd the bulb ith will be on at hte end
// conclusion :-
// A number has an odd number of factors if and only if it is a perfect square.



class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
// @lc code=end


int main(){

    return 0;
}