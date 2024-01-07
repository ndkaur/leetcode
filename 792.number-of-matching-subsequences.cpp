/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
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


class Solution0 { // tle
public:
    bool check(string& s, string& word){
        int n = s.size();
        int m = word.size();
        int i = 0; 
        int j = 0;
        while(i<n && j<m){
            if(s[i]==word[j]){
                i++; 
                j++;
            }
            else {
                i++;
            }
        }
        if(j!=m)
            return false;
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            if(check(s, words[i])==true){
                cnt++;
            }
        }
        return cnt;
    }
};

// we need to check each subsqeuence , but the possiblity is the words can be repeated so use map to store them 

class Solution1 { 
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();

        int cnt = 0;
        unordered_map<string,int> mp; 

        for(int i=0; i<m; i++){
            mp[words[i]]++;
        }

        for(auto itr:mp){
            int i = 0; 
            int j = 0;
            string temp = itr.first;
            while(i<n && j<temp.size()){
                if(s[i]==temp[j]){
                    i++; 
                    j++;
                }
                else {
                    i++;
                }
            }
            if(j==temp.size())
                cnt+= itr.second;
        }
        return cnt;
    }
};

// using binary search 

// abcde ,  { a, bb, acd, ace }
//  a -> {0}
// b-> {1} 
// c-> {2} , 
// d->{3} , 
// e ={4}

// a , last = -1 so check of a using upper bound 
// we want to find that if a exist after the occurence of last index 
// and upper bound gives us the > values so use it .

// use a 2d array to store the char and all its occurence indexes in S
// eg  abacdc 
//  so for a -> {0,2}   for c->{3,5}

class Solution { 
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();

        vector<vector<int>> store(26);
        for(int i=0; i<n; i++){
            store[s[i]-'a'].push_back(i); // store the index where it occurs in string S
        }

        int cnt = 0;

        for(auto word:words){
            int last = -1;
            bool found = true;
            // word = bcd so check for each b , c, d
            for(auto ch: word){
                // find the next occurence idx of char after the last idx 
                auto ub = upper_bound(store[ch-'a'].begin(), store[ch-'a'].end(), last);
                // find the indx gretaer than last idx where the same char present
                // eg -> b ={0, 4, 6}  last =-1 
                // ub(-1) = 0 so that means one more b exist at idx 0 
                
                // if ub not found 
                if(ub==store[ch-'a'].end())
                    found = false;
                else  // when ub found then change the last idx value 
                    last = * ub;
            }
            // if the word is found
            if(found)
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end


int main(){

    return 0;
}