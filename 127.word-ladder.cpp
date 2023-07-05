/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        // for each word change each of its char from a to z 
        // and check if it exists in the word list 
        set<string> s(wordList.begin(), wordList.end());
        // bfs 
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord); // set is also working as visited array here 
        // keep on removing which are seen in set 

        while(q.size()){
            string word = q.front().first;
            int cnt  = q.front().second;
            q.pop();
            if(word==endWord)
                return cnt;
            // for each word change each char a to z
            for(int i=0; i<word.size(); i++){
                // hit 
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    // h will change -> ait, bit, cit
                    word[i] = ch;
                    if(s.find(word)!=s.end()){ // word found in set
                        q.push({word,cnt+1});
                        s.erase(word);
                    }
                }
                // zit-> hit // we need the original word to change its next index chars 
                word[i] = original;
            }
        }
        return 0;
    }
};


we are moving level by level so its bfs  

beginWord = "hit", endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
set = ["hot","dot","dog","lot","log","cog"]

begin = hit , 1 
q= {{hit,1}}
i=1 ait bit cit zit -> nothing found  in set 
i=2 hat hbt hct ... hot ...zot -> hot found in set  
so remove from "hot" ans cnt = 2 

set = ["dot","dog","lot","log","cog"]
q= {{hot,2}}
i=1 aot, bot, cot, dot , lot  => dot, lot
q = {{dot,3}, {lot,3}}

set = ["dog","log","cog"]
q = {{dot,3}, {lot,3}}
word = dot 
i=1 aot, bot,  cot, zot => nothing
i=2 dat dbt  => nothing
i=3 doa, dob, doc,  dog 
q ={{lot,3}, {dog,4}}

set = ["log","cog"]
q ={{lot,3}, {dog,4}}
word = lot 
i=1 aot bot => nothing 
i=2 lat lbt lct => nothing
i=3 loa lob loz => nothing 

set = ["log","cog"]
word = dog 
i=1 aog bog, cog , => 
q{{cog, 5}}
cog = end word 
so return 5 

// @lc code=end


int main(){

    return 0;
}