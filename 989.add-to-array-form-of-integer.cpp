/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        reverse(a.begin(),a.end());//reversed beacuse i dont want to iterate i from back
        vector<int> b; 
        
        // for converting the long int value of k into an array
        while(k>0){
            b.push_back(k%10);
            k/=10;
        }
        vector<int> out;
        //here adding is done like the way kids do .. add and take carry 
        int n=a.size();
        int m=b.size();
        int i=0, j=0, carry=0;
        while(i<n || j<m || carry>0){
            int sum=0;
            if(i<n) 
                sum=sum+a[i++];
            if(j<m)
                sum=sum+b[j++];
            sum=sum+carry;
            out.push_back(sum%10);
            carry=sum/10;
        }
        reverse(out.begin(),out.end());

        return out;
    }
};

// ........................................................................

// CASE-2
// when k is small but other number is long. 
// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& a, int k) {
//         int n=a.size();
//         vector<int> out;
//         reverse(a.begin(),a.end());
//         int i=0,carry;carry=k;
//         while(i<n || carry>0){
//             if(i<n)
//                 carry=carry+a[i++];
//             out.push_back(carry%10);
//             carry/=10;
//         }
//         reverse(out.begin(),out.end());
//         return out;
//     }
// };

// ...........................................................................

// @lc code=start
// CASE-1
// this solution is not valid because the value of k goes upto 10000...so 
// we will use another method method for adding long numbers

// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& A, int K) {
//         int len =A.size();
//         int sum =0 ;
//         for(auto x: A){
//             sum = sum*10+x;    
//         }
//         sum+=K;
//         vector<int> out;
//         while(sum){
//             out.push_back(sum%10);
//             sum/=10;
//         }
//         reverse(out.begin(), out.end());
//         return out;
//     }
// };

// @lc code=end


int main(){
    Solution sol;
    vector<int> A={1,2,0,0};
    int k;
    vector<int> out=sol.addToArrayForm(A,34);
    print(out);
    return 0;
}