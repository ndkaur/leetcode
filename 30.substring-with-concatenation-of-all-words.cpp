/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
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
// O(N * M * L), where N is the length of the input string, M is the number of words, and L is the length of each word.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n= s.size();
        int wlen = words.size();
        int len = words[0].size();

        if(n < wlen*len)
            return {};

        unordered_map<string,int> mp;
        for(auto word:words){ // count for each word freq
            mp[word]++;
        }
        
        vector<int> ans;
        // cant go till end of string as we need to check a particualr len 
        // total len requird = 2 words , each len of 3 = 2*3 =6
        for(int i=0; i<= n- (wlen * len); i++){
            unordered_map<string,int> seen;

            int cnt= 0;

            for(int j=i; j< i+ (wlen*len); j+=len){
                // take sunstr of required len from each idx 
                string word= s.substr(j, len);
                seen[word]++;
                // word found
                if(seen[word] <= mp[word])
                    cnt++;
                else 
                    break;
            }
            if( cnt == wlen)
                ans.push_back(i);
        }
        return ans;
    }
};

// each word in words is of same len so toal len of all words will be = sze of word array *  len of each word 
// we will use our for loop using above statement
// make a map to count the fre of words 
// use for loops and check if the words are reapeated only the freq no of times 


// @lc code=end


int main(){

    return 0;
}