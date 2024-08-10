/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
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

//  time ->O(2n) // o(n) for r to travel and O(n) for l to remove chars
// space ->O(N) set space 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n= s.size();
        int len=0;
        int l=0;
        int r=0; 
        set<int> st;
        while(l<n && r<n){
            if(st.find(s[r]) == st.end()){ // if the char doesnot exist in set
                st.insert(s[r]);
                r++; //move r ahead 
                len = max(len, r-l); // we moved r ahead so no need to add 1 to len otherwise should have done like  r-l+1
            }
            else{// if already exist in stack then remove all the ele of stack till dublicate exists 
                st.erase(s[l]);
                l++;
            }
        }
        return len;
    }
};


// optimised sol use a map to keep track of index 
// left marks the first occurence of char 
// right idx move on till if dublicate of already visited char exists 
// if dublicate then we replace the left idx with the right idx +1 .. we skip the char in between

class Solution { //O(N)
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int len=0;
        int l=0;
        int r=0;
        vector<int> mp(256,-1);// array of 256 cause it will include all ascii values all alphabets 
        while(r<n){
            if(mp[s[r]]!=-1){ // already visited 
                // move the left idx to right idx +1 
                l = max(mp[s[r]]+1, l); // take max if to see if its not in that range already 
            }
            // not using a else loop as each time we want to update the value of r 
            mp[s[r]] = r; // update the last seen idx of the char 
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int i =0;
        int j =0;
        int ans =0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}