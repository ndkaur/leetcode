/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
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

class Solution {  // o(n^2)
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n= arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int s=0;
            int x=0;
            for(int j=i;j<n;j++){
                s+= arr[j];
                // update sum till the len is even and the len doesnot become odd
                if(x%2==0)// even
                    sum+=s;
                x++;
            }
        }
        return sum;
    }
};
//  0 1 2 3 4
// [1,4,2,5,3]
// find sub arrays with each odd len 
//  1-> 1,2,3,4,5
//  3-> (1,4,2)  (4,2,5)  (2,5,3)
//  5-> (1,4,2,5,3)

// nums -> 1  2   3   4  5
// time->  3  4   5   3  3
// total  1*3 + 2*4 + 3*5 + 4*3 +5*3 =58 

// so main task is to find the no of times each digit is repeating in the sub arrays of all types of len 
//  no of subarrays starting at that idx 
// idx  start of subarray     end of subarray 
// 0       5                      1
// 1       4                      2
// 2       3                      3  
// i       n-i                    i+1 
//  total is the number of time digit is coming in all sub arrays of  both odd and even len 
//  so the formula becomes  total =  (n-i) * (i+1)
//  if total/2 odd -> add 1



class Solution {  // o(n)
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n= arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int start= n-i;
            int end= i+1;
            //  total = no of times each i digit occur 
            int total= start*end;
            int odd= total/2;
            if(total%2==1) // odd 
                odd++;
            // no of time * arr(i) 
            ans+= odd * arr[i];
        }
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> arr= {1,4,2,5,3};
    int ans = sol.sumOddLengthSubarrays(arr);
    cout<<ans;
    return 0;
}