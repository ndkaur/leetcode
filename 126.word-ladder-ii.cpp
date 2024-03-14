/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
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


// memory limit exceeded 

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while(q.size()){
            vector<string> vec = q.front();
            q.pop();
            // if we at level 0 then vector will have only one word 
            // if we at leave 1 then vector will have 2 words 
            // it simply means when a particular level is completely used up from queue then only we will remove the used 
            // lastusedwords store in set 
            if(vec.size()>level){
                level++;
                // erasing words that are alredy used 
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            // we made the word 
            if(word == endWord){
                // first sequence it will automatically will be the smallest one 
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                // one sequence is already added 
                //we will only add the next sequence when the size is same to smallest len sequence 
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            
            for(int i=0; i<word.size(); i++){   
                char original = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if (st.count(word) > 0){ 
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        // backtrack -> cause there might be some other smller path 
                        vec.pop_back();
                    }
                }
                // changing other char of the word 
                word[i] = original;
            }
        }
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}