/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum =0;
        for(int i =0; i<n; i++){
            int mn = arr[i];
            for(int j=i; j<n; j++){
                mn = min(mn, arr[j]);
                sum = (sum + mn ) % 1000000007;
            }
        }
        return sum;
    }
};



class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> left(n), right(n);
        // from left to right 
        for(int i=0; i<n; i++){
            while(stk.size() && arr[stk.top()]>arr[i]){ // decreasing order
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i); 
        }

        while(stk.size()){
            stk.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(stk.size() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        long long ans =0;
        // finding final ans
        for(int i=0; i<n; i++){
            ans = (ans + (long long)arr[i] * (i-left[i]) * (right[i]-i))%mod;
        }
        
        return (int)ans;
    }
};


// 0  1 2 3 <- idx

// 3  1 2 4 <- nums

//-1 -1 1 2 <- left = prev smaller element behind that index 
// 1  4 4 4 <- right = prev smaller element 

// i=0 , 3 * (0-(-1)) * (1-0) = 3*1*1 = 3
// i=1, 1 * (1-(-1)) * (4-1)= 1*2*3 = 6
// i=2, 2 * (2-1) * (4-2) = 2*1*2 = 4 
// i=3 , 4 * (3-2) * (4-3) = 4*1*1= 4 
    //                          ans=17

    // logic so cnt the no of prev smaller elem to the curr elem = i-left[i]=a1 
// no of next smlller elemt from curr elem = right[i]-i = a2
// these are the elem inbetween 
// so total no of subarrays with the curr val as minimum = a1*a2

class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        //calculate  next smaller to left and right
        //and count number of times a[i] is the min
        int n = a.size();
        vector<int> left(n,-1); //idx of smaller element tha  a[i] to left
        stack<int> s;
        for(int i=0;i<n;i++){
            int cur = a[i];
            while(!s.empty() && cur<= a[s.top()]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        vector<int> right(n,n);
        for(int i=n-1;i>=0;i--){
            int cur = a[i];
            while(!s.empty() && cur< a[s.top()]){
                //look carefully there's no equal sign here as we can count double occurrences twice
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }
        
        int ans =0 ;
        long mod = 1e9 +7;
        for(int i=0;i<n;i++){
            int cl = i- (left[i]+1)+1;
            int cr = (right[i]-1)-i + 1;
            ans = (ans + (long)a[i]*cl*cr)%mod;
            
        }
        return ans;
    }
};

// @lc code=end


