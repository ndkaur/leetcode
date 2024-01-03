/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
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
    int lengthLongestPath(string input) {
        int n = input.size();
        int mx = 0;
        stack<pair<int,int>> stk; // level, max length
        stringstream data(input);
        string temp;
        while(getline(data, temp, '\n')){ // this gives string till next \n is encountered
            int level = 0;
            // no of \t means we switched to next file level path
            //check if t is at the beginning then level change ie path change 
            // temp[0] =t then temp[1] check and so on 
            while(temp[level]=='\t'){
                level++;
            }

            int lev = level;
            // this loop makes sure that the next coming levl is same or smaller 
            // we remove it and give the next coming string a chance to find if max len is possible from it or not 
            // the last string will have many t so which means curr level will will gretaer than the prev level 
            // that means we will add the next coming len into prev  
            while(stk.size() && stk.top().first>=lev){
                stk.pop();
            }
            
            int prev = 0;
            if(stk.size())
                prev = stk.top().second + 1; // adding the '\' int length
            // we dont want t in the ans so remove its cnt ie remove lev
            int curr = temp.size()-lev; // subtracting the number of t
            auto found =  temp.find('.');
            if(found!=string::npos){
                mx= max(mx, prev+curr);
            }
            stk.push({lev, prev+curr});
        }
        return mx;
    }
};

//"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
// i=0 , num = 0
// @lc code=end


int main(){

    return 0;
}