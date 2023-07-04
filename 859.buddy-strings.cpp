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
       int lenA= A.size();
       int lenB= B.size();
       if(lenA!=lenB) return false;
       int len= unordered_set<char>(A.begin(),A.end()).size();
       if(A==B && len<lenB) return true;

        vector<int> indexDiff;
        for(int i=0;i<lenA;i++){
            if(A[i]!=B[i])
                indexDiff.push_back(i);
            if(indexDiff.size()>2) return false;
       }
       return indexDiff.size()==2 && A[indexDiff[0]]==B[indexDiff[1]] && A[indexDiff[1]]== B[indexDiff[0]];
    }
};


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if(s==goal){
            // can have same chars then false aa == aa true
            // ab , ab  false
            set<char> st(s.begin(), s.end());
            // aa -> set.size() =1 // ab ->size= 2
            return st.size() < goal.size();          
        }
        if(s.size()!=goal.size())
            return false;
        int i =0;
        int j = n-1;
        while(i<j && s[i]==goal[i]){
            i++;
        }
        while(j>=0 && s[j]==goal[j]){
            j--;
        }
        if(i<j)
            swap(s[i], s[j]);
        return s==goal;
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