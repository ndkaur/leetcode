/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

// @lc code=end

//  A -65  Z= 90 
//  a= 97  z=122
// Z- capital char = +ve result
// Z - lower case letter = -ve result;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for(char c : word){
            if('Z' - c >= 0)
                capitalCount++; 
        }
        return (capitalCount == word.size() || (!capitalCount) || (capitalCount == 1 && 'Z' - word[0] >= 0));
                // all capital                 // all lower case        //  only starting letter is capital
           
    }
};


class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        // upper case range -> 65 to 90
        // lower case range -> 97 to 122
        if(n==1)
            return true;
        if(word[0]<91 && word[1]<91){ // both upper case 
            for(int i=2; i<n; i++){
                if(word[i] > 96)// any lower case found
                    return false;
            }
            return true; // all upper case no lower found
        }
        else{ // when only starting is upper case or all lower 
            for(int i=1; i<n; i++){
                if(word[i] < 91)
                    return false; // only first letter can be capital no one else 
            }
            return true;
        }
    }
};

int main(){
    Solution sol;
    string word="FlaG";
    bool out=sol.detectCapitalUse(word);
    cout<<out;
    return 0;
}