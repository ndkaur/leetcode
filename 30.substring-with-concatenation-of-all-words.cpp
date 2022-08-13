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
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n= s.size();
        int wlen = words.size();
        int len = words[0].size();

        unordered_map<string,int> mp;
        for(auto word:words){ // count for each word freq
            mp[word]++;
        }
        
        vector<int> ans;
        // cant go till end of string as we need to check a particualr len 
        for(int i=0; i<n-wlen * len + 1 ;i++){
            unordered_map<string,int> seen;

            int j=0;
            for(; j< wlen;j++){
                string word= s.substr(i+j *len , len);
                // word found
                if(mp.find(word)!= mp.end()){
                    seen[word]++; // count its freq 

                    if(seen[word] > mp[word]) // word got repeated than what was required count
                        break;
                }
                else break;
            }
            if(j== wlen)
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