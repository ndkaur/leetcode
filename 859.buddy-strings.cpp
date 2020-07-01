/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
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
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())
            return false;
        if(A==B){
            //check if element is repeating or not
            map<char,int> m;
            for(auto x:A){
                m[x]++;
                if(m[x]>=2) //if no repets more than two times
                    return true;
            }
            return false;
        }
        //when A!=B ie when some elements are equal ..some are not equal
        vector<int> check;
        for(int i=0;i<A.size();i++)
            if(A[i]!=B[i])
                check.push_back(i);
        
            //if check has more than or less than 2 elements
            if(check.size()!=2)
                return false;
            // if check has exactly only 2 nos
            swap(A[check[0]],A[check[1]]);
            return A==B;
            
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    string A= "abad",B="baad";
    bool out=sol.buddyStrings(A,B);
    cout<<out;
    return 0;
}