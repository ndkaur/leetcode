/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
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

//O(n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        for(auto letter:letters){
            if(letter > target){
                return letter;
            }
        }
        return letters[0];
    }
};

// O(logn)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l= 0;
        int h = n-1;
        if(letters[n-1]<= target)
            return letters[0];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(letters[mid]> target)
                h= mid-1;
            else 
                l= mid+1;
        }
        return letters[l];
    }
};
// @lc code=end


int main(){

    return 0;
}