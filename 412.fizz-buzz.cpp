/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
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
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1; i<=n; i++){
            if(i%3 == 0){
                if(i%5==0)
                    ans.push_back("FizzBuzz");
                else 
                    ans.push_back("Fizz");
            }
            else if(i%5 == 0)
                ans.push_back("Buzz");
            else 
                ans.push_back(to_string(i));
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}