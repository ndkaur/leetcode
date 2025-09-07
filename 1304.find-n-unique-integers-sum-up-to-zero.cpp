/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> output;
        int sum =0;
        for(int i=0;i<n-1;i++){
            sum=sum +i;
            output.push_back(i);
        }
        output.push_back(-sum);
        return output;
    }
};


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n==1)
            return {0};
        if(n%2==0){
            for(int i=1; i<=n/2; i++){
                ans.push_back(i);
                ans.push_back(-(i));
            }
        }
        else{
            int val = n/2;
            int rem = n-val;// even value 
            int sum=0;
            for(int i=1; i<=rem; i++){
                sum+=i;
                ans.push_back(i);
            }
            for(int i=1; i<=val; i++){
                if(i==val){
                    ans.push_back(-sum);
                    break;
                }
                sum-=i;
                ans.push_back(-i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// @lc code=end
int main(){
    Solution sol;
    int sum,n;
    vi output;
    output=sol.sumZero(10);
    print(output);
    return 0;
}