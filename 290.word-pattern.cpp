/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start


class Solution {
public:
    vector<string> splitIntoWords(const string& sentence) {
        istringstream iss(sentence);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
    bool wordPattern(string pattern, string s) {
        // pattern ch 
        // s -> string of words
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        vector<string> words = splitIntoWords(s);

         if(pattern.size() != words.size())
            return false;


        for(int i=0; i<pattern.size(); i++){
            if(mp1.find(pattern[i])!=mp1.end() && mp1[pattern[i]]!=words[i]){
                return false;
            }
            if(mp2.find(words[i])!=mp2.end() && mp2[words[i]]!=pattern[i])
                return false;
            mp1[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i]; 
        }
        return true;
    }
};

class Solution0 {
public:
    bool wordPattern(string pattern, string s) {
        int pl= pattern.size();
        int sl= s.size();
        vector<string> str;
        string temp="";
        // check by length 
        for(int i=0;i<sl;i++){
            if(s[i]==' '){
                str.push_back(temp);
                temp="";
            }
            else {
                temp += s[i];
            }
            if(i==sl-1)// reached the end
                str.push_back(temp);
        }
        if(pl!=str.size()) return false;
        // check by word compare position
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        for(int i=0;i<pl;i++){
            if(m1.find(pattern[i])!=m1.end() && m1[pattern[i]]!=str[i]) 
                return false;
            if(m2.find(str[i])!=m2.end() && m2[str[i]]!= pattern[i])
                return false;
            m1[pattern[i]] = str[i];
            m2[str[i]]= pattern[i];
        }
        return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_map<char,string> char_map; // a->dog
        unordered_map<string,char> word_map; // dog-> a
        stringstream str(s); // break the words from string s
        string word; // store words from stream 
        int i=0;
        while(str >> word){
            if(i==n) return false;
            if(char_map.count(pattern[i]) != word_map.count(word)) // the time 'a' exist is same as the times 'dog' exist
                return false;
            if(char_map.count(pattern[i])){
                if((word_map[word] != pattern[i]) || (char_map[pattern[i]] != word)) // check both a->dog and dpg->a
                    return false;
            } 
            else { // visiting fro the first time the insert in map
                char_map.insert({pattern[i],word});
                word_map.insert({word,pattern[i]});
            }
            i++;
        }
        return i==n;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string pattern ="abba";
    string s="dog cat cat dog";
    bool ans = sol.wordPattern(pattern,s);
    cout<<ans;
   return 0;
}