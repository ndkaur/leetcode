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

// time limit exceded
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;

        queue<vector<string>> q;
        q.push({beginWord});

        set<string> s(wordList.begin(), wordList.end());

        vector<string> usedOnLevel; // we need to remove those last added string from set 
        // this array weill keep track of those strings even when we come out of loop
        usedOnLevel.push_back(beginWord);

        while(q.size()){
            int n = q.size();
            for(int i=0; i<n; i++){
                vector<string> level = q.front();
                q.pop();
                vector<string> temp= level;

                string word = level.back();
                // last word reached
                if(word==endWord){
                    ans.push_back(level);
                }

                for(int i=0;i<word.size(); i++){
                    char original = word[i];
                    for(char ch='a'; ch<='z'; ch++){
                        word[i] =ch;
                        if(s.find(word)!=s.end()){
                            temp.push_back(word);
                            q.push({temp});
                            usedOnLevel.push_back(word);
                            // at same there can be different possible paths for strings to choose from 6
                            temp.pop_back(); // backtrack if any other sequence possible 
                        }
                    }
                    word[i]= original;
                }
            }
            // remove the word from set after all the strings on that level are done 
            for(auto str:usedOnLevel){
                s.erase(str);
            }
        }
        return ans;
    }
};

// tle 
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Creating a queue ds which stores the words in a sequence which is
        // required to reach the targetWord after successive transformations.
        queue<vector<string>> q;

        // BFS traversal with pushing the new formed sequence in queue 
        // when after a transformation, a word is found in wordList.

        q.push({beginWord});

        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
       
        // A vector to store the resultant transformation sequence.
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // Now, erase all words that have been
            // used in the previous levels to transform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();

            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {   
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    { 
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the queue.
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
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