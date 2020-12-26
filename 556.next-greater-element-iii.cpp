/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
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
    int nextGreaterElement(int n){
        string s = to_string(n); // n is in form of string now
        int i =s.size()-2;
        for( ; i>=0;i--){ // starting backward
            if(s[i]<s[i+1]) // the second digit is smaller than first digit 21 , 2>1 gives 12
                break;
        }
        if(i<0) // n doesnot exist
            return -1;
        for(int j=s.size()-1; j>i;j--){
            if(s[j]>s[i]){
                swap(s[i],s[j]);
                break;
            }
        }
        reverse(s.begin()+i+1,s.end());
        long ans = stol(s); //string to long int conversion
        return ans > INT_MAX ? -1 :ans; // result larger than 32 bit 
    }
};
// @lc code=end



int main(){
   
    return 0;
}