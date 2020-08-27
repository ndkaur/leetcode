/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
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
    int sumno(int num){ // found the sum of given n
        int sum=0;
        while(num){
            sum=sum+(num%10);
            num=num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> arr(50); // to mark the nums
        int count=0;
        for(int i=1;i<=n;i++){
            arr[sumno(i)]++; // increase count when i comes and repreas the sum
        }
        int mx=*max_element(arr.begin(),arr.end());
        
        for(int i:arr){
            if(i==mx) count++; // to count the no of times max comes 
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=13;
    int ans=sol.countLargestGroup(n);
    cout<<ans;
    return 0;
}