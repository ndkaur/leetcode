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
// time->  3  5   3   4  4
// total  1*3 + 2*5 + 3*3 + 4*4 + 5*4 =58 

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




        // sum = arr[i] * number of times arr[i] is included in all the subaarays formed
        // number of times lets call it = total 
        // occurence of arr[i] in even length subarray  = total /2
        // occurence of arr[i] in odd length subaaray = (total+1)/2
        // now how to find total ?
        //                0 1 2 3 4
        // suppose arr = {1,4,2,5,3}
        // checking no of subarrays on the left side of arr[2] = {2},{2,4},{2,4,1} 
        // left side of arr[2]  = 3 ie formulaa => i+1  (i=2  so 2+1 = 3)
        // checking no of subarrays on the right side of arr[2] = {2}, {2,5},{2,5,3}
        // but subarray {2} alreday incuded in left side  so 
        // subarrays on right side = 2 => n-i-1  (5-2-1 =2)
        // arr[2] will also occur in the full arr = {1,4,2,5,3} so cnt =1 
        // number of subarrays on right side = n-i+1 + cnt = n-i+1 +1 => n-i
        // no of left subarray = i+1
        // no of right subarray = n-i
        // total = left*right
        // total odd length subarrays = (t+1)/2 = (left*right+1)/2

        // so sum += nums[i] * no of odd subarrays it is included in
        //  sum += nums[i] *( (i+1)*(n-i))+1 /2
        // i=0 sum += 1 * (1*5)+1 /2 = 5+1 = 6/2 = 3 
        // sum = 3 
        // i=1  sum += 4 * (2*4)+1 = 9/2 = 4 *4 =16
        // sum = 3+16 = 19 
        //  i=2  sum += 2 * (3*3)+1 = 10/2 = 5*2 = 10
        //  sum = 19 + 10 = 29 
        // i=3  sum += 5  * (4*2)+1 = 9/2 = 5*4 = 20
        // sum = 29+20 = 49
        //  i=4  sum += 3 * (5 * 1)+1 = 6/2 = 3*3=9
        // sum = 49 + 9 = 58 

 class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            int total = (i+1) * (n-i) ;
            int odd  = (total+1)/2;
            sum += arr[i] * odd;
        }
        return sum;
    }
};


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