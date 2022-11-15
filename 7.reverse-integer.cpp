/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
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
    int reverse(int x) {
        long long int  r = abs(x);
        long long int rev = 0;
        while(r){
            long long int rem = r%10;
            rev = rev*10+rem;
            r = r/10;
        }
        if(rev > -pow(2,31) && rev < pow(2,31)-1){
            if(x<0){
                return (-1)* rev;
            }
            else{
                return rev;
            }
        }
        return 0;
    }
}; 


// @lc code=end


int main(){

    return 0;
}