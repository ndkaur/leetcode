/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start


class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while(num){
            if(num%2==0)
                num>>=1;
            else 
                num--;
            cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int numberOfSteps (int num) {
        int count=0;
        if(num==0)
            return 0;
        while(num!=0){
            if(num%2==0){
                num=num/2;
                count++;
            }
            else {
                num=num-1;
                count++;
            }
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int num=123;
    int ans=sol.numberOfSteps(num);
    cout<<ans;
    return 0;
}